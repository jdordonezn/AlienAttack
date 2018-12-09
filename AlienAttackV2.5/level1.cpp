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

    soundShot=new QMediaPlayer();
    playList=new QMediaPlaylist();
    playList->addMedia(QUrl("qrc:/Sound/gun.wav"));
    soundShot->setPlaylist(playList);
    soundShot->setVolume(100);
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
                    lcd_score->display(score);
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
                        _message="GAME OVER :c";
                        SeeMsgScreen();
                    }
                    else{
                        numHealth--;
                        lcd_health->display(numHealth);
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
        close();
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

        if(soundShot->state()==QMediaPlayer::PlayingState){
            soundShot->setPosition(0);
        }
        else if(soundShot->state()==QMediaPlayer::StoppedState){
            soundShot->setVolume(50);
            soundShot->play();
        }

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
        if(flagLevel==1){
            makeAlienLeft();
        }
        else if (flagLevel==2){
            makeAlienRight();
            makeAlienLeft();
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
