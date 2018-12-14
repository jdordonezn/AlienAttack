#include "level1.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new myscene(0,0,1000,620);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background: transparent");
    movie=new QMovie(":/Pictures/fondo.gif");
    ui->label1->setMovie(movie);
    movie->start();
    lcd_score=ui->lcd1;
    lcd_score->display(score);
    lcd_health=ui->lcd;
    lcd_health->display(numHealth);

    timer=new QTimer();
    createEnemy=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(createEnemy,SIGNAL(timeout()),this,SLOT(nuevoEnemy()));
    timer->start(35);
    createEnemy->start(2000);
    player=new Jugador();
    scene->addItem(player);
    player->setCd(0.5);

    //Conection to arduino

    timer_control=new QTimer;
    control = new QSerialPort(this);
    connect(timer_control,SIGNAL(timeout()),this,SLOT(Joy1()));
    //timer_control->start(1000);
    qDebug()<<"triggered";
    control->setPortName("/dev/ttyACM1");

    if(control->open(QIODevice::ReadWrite)){
        qDebug()<<"Puerto abierto";
        //Ahora el puerto seria está abierto
        if(!control->setBaudRate(QSerialPort::Baud9600)) //Configurar la tasa de baudios
            qDebug()<<control->errorString();

        if(!control->setDataBits(QSerialPort::Data8))
            qDebug()<<control->errorString();

        if(!control->setParity(QSerialPort::NoParity))
            qDebug()<<control->errorString();

        if(!control->setStopBits(QSerialPort::OneStop))
            qDebug()<<control->errorString();

        if(!control->setFlowControl(QSerialPort::NoFlowControl))
            qDebug()<<control->errorString();
        timer_control->start(20);
    }
    else{
        qDebug()<<"Serial COM3 not opened. Error: "<<control->errorString();
    }

    //sonido de balas
    soundShot=new QMediaPlayer();
    playList=new QMediaPlaylist();
    playList->addMedia(QUrl("qrc:/Sound/gun.wav"));
    soundShot->setPlaylist(playList);
    soundShot->setVolume(100);

    //musica de fondo
    playlist2 = new QMediaPlaylist();
    playlist2->addMedia(QUrl("qrc:/audios/audios/Good Starts.mp3"));
    playlist2->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist2);
    music->setVolume(100);
    music->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::animar(){

    if(flagJump && player->getPy()<=575){
        player->salto();
    }
    else{
        player->setPy(575);
        player->setVy(-50);
        flagJump=false;
    }

    for(int i=0;i<explotions.size();i++){
        if(explotions.at(i)->getCont()!=6){
            explotions.at(i)->fotograma();
        }
        else{
            scene->removeItem(explotions.at(i));
            explotions.removeAt(i);
        }
    }
    player->mover();



    for(int i=0;i<bullets.size();i++){

        if(!bullets.at(i)->collidingItems().empty() && !bullets.at(i)->collidesWithItem(player)){
            if(!bullets.at(i)->collidesWithItem(scene->getBordeIzquierdo()) && !bullets.at(i)->collidesWithItem(scene->getBordeDerecho())){
                if(bullets.at(i)->chocarWithEnemies(enemies,scene)){
                    score++;
                    lcd_score->display(lcd_score->value()+1);
                }
            }
            scene->removeItem(bullets.at(i));
            bullets.removeAt(i);
        }
        else{
            bullets.at(i)->mover();
        }
    }

    for(int i=0;i<granades.size();i++){
        if(granades.at(i)->fueraDeRango()){
            scene->removeItem(granades.at(i));
            granades.removeAt(i);
        }
        else{
            if(!granades.at(i)->collidingItems().empty() && !granades.at(i)->collidesWithItem(player)){
                if(granades.at(i)->chocarWithEnemies(enemies,scene)){
                    score++;
                    newExplotion=new explotion();
                    newExplotion->setPx(granades.at(i)->getPx());
                    newExplotion->setPy(granades.at(i)->getPy()-40);
                    newExplotion->setPos(newExplotion->getPx(),newExplotion->getPy());
                    explotions.append(newExplotion);
                    scene->addItem(newExplotion);
                    lcd_score->display(score);
                    scene->removeItem(granades.at(i));
                    granades.removeAt(i);
                }
            }
            else{
              granades.at(i)->mover();
            }

        }
    }

    for(int i=0;i<enemies.size();i++){

        if(!enemies.at(i)->collidingItems().empty()){
            if(enemies.at(i)->collidesWithItem(scene->getBordeIzquierdo())  || enemies.at(i)->collidesWithItem(player)){
                if(enemies.at(i)->collidesWithItem(player)){
                    if(numHealth==0){
                        if(!multijugador){
                            _message="GAME OVER :c";
                            SeeMsgScreen();
                        }
                        else{
                            scene->removeItem(player);
                        }
                    }
                    else{
                        numHealth--;
                        lcd_health->display(lcd_health->value()-1);
                    }
                }
                scene->removeItem(enemies.at(i));
                enemies.removeAt(i);
            }
        }
        else{
            enemies.at(i)->moverE();
        }
    }


}


void MainWindow::keyPressEvent(QKeyEvent *ev){
    if(ev->key()==Qt::Key_Escape){  //Tecla para dar la orden de cerrar la simulación
        optionSave=new optSave();
        optionSave->setLcd_s1(lcd_score);
        optionSave->setLcd_h1(lcd_health);
        optionSave->setPlayer(player);
        optionSave->setEnemies(enemies);
        optionSave->show();
        ev->accept();
    }
    if(ev->key()==Qt::Key_A  && player->getPx()>-100){  //Tecla para dar la orden de cerrar la simulación
        player->setVx(-15);
        player->setVUnit(-1);
        ajusteRifle=-15;
        vUnitShot=-1;
        ev->accept();
    }
    if(ev->key()==Qt::Key_W){  //Tecla para dar la orden de cerrar la simulación
        flagJump=true;
        ev->accept();
    }
    if(ev->key()==Qt::Key_D && player->getPx()<990){  //Tecla para dar la orden de cerrar la simulación
        player->setVx(15);
        player->setVUnit(1);
        ajusteRifle=15;
        vUnitShot=1;
        ev->accept();
    }
    if(ev->key()==Qt::Key_Space){
        newBullet=new bullet();
        newBullet->setVUnit(vUnitShot);
        newBullet->setPx(player->getPx()+ajusteRifle);
        newBullet->setPy(player->getPy()+15);
        newBullet->setPos(newBullet->getPx(),newBullet->getPy());
        bullets.append(newBullet);
        scene->addItem(newBullet);
        ev->accept();
        /*
        if(soundShot->state()==QMediaPlayer::PlayingState){
            soundShot->setPosition(0);
        }
        else if(soundShot->state()==QMediaPlayer::StoppedState){
            soundShot->setVolume(50);
            soundShot->play();
        }
        */

    }
    if(ev->key()==Qt::Key_C){
        if(numAvailableGranades>0){
            newGranade=new granade();
            newGranade->setPx(player->getPx());
            newGranade->setPy(player->getPy());
            newGranade->setPos(newGranade->getPx(),newGranade->getPy());
            newGranade->setVUnit(vUnitShot);
            granades.append(newGranade);
            scene->addItem(newGranade);
            numAvailableGranades--;
        }
        ev->accept();
    }

}

int MainWindow::getFlagLevel() const
{
    return flagLevel;
}

void MainWindow::setFlagLevel(int value)
{
    flagLevel = value;
}

void MainWindow::nuevoEnemy()
{

    if(numAvailableEnemies>0){
        switch (flagLevel) {
            case 1:
                makeAlienLeft();
                break;
            case 2:
                makeAlienRight();
                makeAlienLeft();
                break;
            case 3:
                makeAlienUp();
                break;
        }
    }
    else {
        if(score<numMinScore){
            _message="GAME OVER :c";

        }
        else{
            _message="YOU WIN!!";

        }
        SeeMsgScreen();
    }
}


int MainWindow::getScore() const
{
    return score;
}

void MainWindow::setScore(int value)
{
    score = value;
}

void MainWindow::hola()
{

}


bool MainWindow::getMultijugador() const
{
    return multijugador;
}

void MainWindow::setMultijugador(bool value)
{
    multijugador = value;
}

int MainWindow::getNumHealth() const
{
    return numHealth;
}

void MainWindow::setNumHealth(int value)
{
    numHealth = value;
}

QString MainWindow::getMessage() const
{
    return _message;
}

void MainWindow::setMessage(const QString &message)
{
    _message = message;
}

QList<enemy *> MainWindow::getEnemies() const
{
    return enemies;
}

void MainWindow::setEnemies(const QList<enemy *> &value)
{
    enemies = value;
}

QList<explotion *> MainWindow::getExplotions() const
{
    return explotions;
}

void MainWindow::setExplotions(const QList<explotion *> &value)
{
    explotions = value;
}

QTimer *MainWindow::getTimer() const
{
    return timer;
}

void MainWindow::setTimer(QTimer *value)
{
    timer = value;
}

QList<granade *> MainWindow::getGranades() const
{
    return granades;
}

void MainWindow::setGranades(const QList<granade *> &value)
{
    granades = value;
}

granade *MainWindow::getNewGranade() const
{
    return newGranade;
}

void MainWindow::setNewGranade(granade *value)
{
    newGranade = value;
}

QList<bullet *> MainWindow::getBullets() const
{
    return bullets;
}

void MainWindow::setBullets(const QList<bullet *> &value)
{
    bullets = value;
}

bullet *MainWindow::getNewBullet() const
{
    return newBullet;
}

void MainWindow::setNewBullet(bullet *value)
{
    newBullet = value;
}

bool MainWindow::getFlagJump() const
{
    return flagJump;
}

void MainWindow::setFlagJump(bool value)
{
    flagJump = value;
}

int MainWindow::getVUnitShot() const
{
    return vUnitShot;
}

void MainWindow::setVUnitShot(int value)
{
    vUnitShot = value;
}

int MainWindow::getAjusteRifle() const
{
    return ajusteRifle;
}

void MainWindow::setAjusteRifle(int value)
{
    ajusteRifle = value;
}

int MainWindow::getNumAvailableEnemies() const
{
    return numAvailableEnemies;
}

void MainWindow::setNumAvailableEnemies(int value)
{
    numAvailableEnemies = value;
}

int MainWindow::getNumMinScore() const
{
    return numMinScore;
}

void MainWindow::setNumMinScore(int value)
{
    numMinScore = value;
}

void MainWindow::SeeMsgScreen()
{
    QFont titleFont("comic sans",60);
    createEnemy->stop();
    timer->stop();
    message=new QGraphicsTextItem(_message);
    message->setFont(titleFont);
    message->setPos(200,150);
    message->setDefaultTextColor(Qt::white);
    scene->addItem(message);
    //save();
}

void MainWindow::makeAlienLeft()
{
    newEnemy=new enemy();
    newEnemy->setTypeAlien(1);
    newEnemy->setPos(newEnemy->getPx(),newEnemy->getPy());
    enemies.append(newEnemy);
    scene->addItem(newEnemy);
    numAvailableEnemies--;

}

void MainWindow::makeAlienRight()
{
    newEnemy=new enemy();
    newEnemy->setPx(-50);
    newEnemy->setVx(5);
    newEnemy->setTypeAlien(2);
    newEnemy->setPos(newEnemy->getPx(),newEnemy->getPy());
    enemies.append(newEnemy);
    scene->addItem(newEnemy);
    numAvailableEnemies--;


}

void MainWindow::makeAlienUp()
{
    newEnemy=new enemy();
    newEnemy->setPy(100);
    newEnemy->setPx(850);
    newEnemy->setTypeAlien(3);
    newEnemy->setPos(newEnemy->getPx(),newEnemy->getPy());
    enemies.append(newEnemy);
    scene->addItem(newEnemy);
    numAvailableEnemies--;
}


Jugador *MainWindow::getPlayer() const
{
    return player;
}

void MainWindow::setPlayer(Jugador *value)
{
    player = value;
}

QLCDNumber *MainWindow::getLcd_health() const
{
    return lcd_health;
}

void MainWindow::setLcd_health(QLCDNumber *value)
{
    lcd_health = value;
}

QLCDNumber *MainWindow::getLcd_score() const
{
    return lcd_score;
}

void MainWindow::setLcd_score(QLCDNumber *value)
{
    lcd_score = value;
}



myscene *MainWindow::getScene() const
{
    return scene;
}

void MainWindow::setScene(myscene *value)
{
    scene = value;
}

QMovie *MainWindow::getMovie() const
{
    return movie;
}

void MainWindow::setMovie(QMovie *value)
{
    movie = value;
}

void MainWindow::Joy1(){
    char data;
    int l = 0;
    bool flag=true;


    if(control->waitForReadyRead(100)){

        //Data was returned
        l = control->read(&data,1);

        switch (data) {
        case 'W':
            flagJump=true;
            break;
        case 'D':
            player->setVx(15);
            player->setVUnit(1);
            ajusteRifle=15;
            vUnitShot=1;
            break;
        case 'A':
            player->setVx(-15);
            player->setVUnit(-1);
            ajusteRifle=-15;
            vUnitShot=-1;
            break;
        case 'X':
            newBullet=new bullet();
            newBullet->setVUnit(vUnitShot);
            newBullet->setPx(player->getPx()+ajusteRifle);
            newBullet->setPy(player->getPy()+15);
            newBullet->setPos(newBullet->getPx(),newBullet->getPy());
            bullets.append(newBullet);
            scene->addItem(newBullet);
            break;
        case 'C':
            if(numAvailableGranades>0){
                newGranade=new granade();
                newGranade->setPx(player->getPx());
                newGranade->setPy(player->getPy());
                newGranade->setPos(newGranade->getPx(),newGranade->getPy());
                newGranade->setVUnit(vUnitShot);
                granades.append(newGranade);
                scene->addItem(newGranade);
                numAvailableGranades--;
            }
            break;
        default:
            break;
        }
        qDebug()<<"Response: "<<data;
        flag=false;

    }else{
        //No data
        qDebug()<<"Time out";
    }
}



