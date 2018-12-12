#include "level1multiplayer.h"
#include "ui_level1multiplayer.h"

level1Multiplayer::level1Multiplayer(QWidget *parent) :MainWindow(parent),
    ui(new Ui::level1Multiplayer)
{
    ui->setupUi(this);
    setMultijugador(true);
    connect(getTimer(),SIGNAL(timeout()),this,SLOT(animar2()));
    ui->graphicsView->setScene(this->getScene());
    ui->graphicsView->setStyleSheet("background: transparent");
    this->setMovie(new QMovie(":/Pictures/fondo.gif"));
    ui->label_Fond->setMovie(this->getMovie());
    this->getMovie()->start();
    setLcd_score(ui->lcd_sc1);
    ui->lcd_hl1->display(3);
    setLcd_health(ui->lcd_hl1);
    lcd_score2=ui->lcd_sc2;
    lcd_score2->display(score2);
    lcd_health2=ui->lcd_hl2;
    lcd_health2->display(numHealth2);
    player2=new Jugador();
    player2->setPlayerMan(true);
    player2->setPx(0);
    player2->setPos(player2->getPx(),player2->getPy());
    getScene()->addItem(player2);
    player2->setCd(0.5);
}

level1Multiplayer::~level1Multiplayer(){
    delete ui;
}

void level1Multiplayer::animar2(){

    if(numHealth2==0 && getNumHealth()==0){
        setMessage("GAME OVER :c");
        SeeMsgScreen();
    }

    if(flagJump2 && player2->getPy()<=575){
        player2->salto();
    }
    else{
        player2->setPy(575);
        player2->setVy(-50);
        flagJump2=false;
    }
    for(int i=0;i<explotions2.size();i++){
        if(explotions2.at(i)->getCont()!=6){
            explotions2.at(i)->fotograma();
        }
        else{
            getScene()->removeItem(explotions2.at(i));
            explotions2.removeAt(i);
        }
    }
    player2->mover();

    for(int i=0;i<bullets2.size();i++){

        if(!bullets2.at(i)->collidingItems().empty() && !bullets2.at(i)->collidesWithItem(player2)){
            if(!bullets2.at(i)->collidesWithItem(getScene()->getBordeIzquierdo()) && !bullets2.at(i)->collidesWithItem(getScene()->getBordeDerecho())){
                if(bullets2.at(i)->chocarWithEnemies(getEnemies(),getScene())){
                    score2++;
                    lcd_score2->display(score2);
                }
            }
            getScene()->removeItem(bullets2.at(i));
            bullets2.removeAt(i);
        }
        else{
            bullets2.at(i)->mover();
        }
    }

    for(int i=0;i<granades2.size();i++){
        if(granades2.at(i)->fueraDeRango()){
            getScene()->removeItem(granades2.at(i));
            granades2.removeAt(i);
        }
        else{
            if(!granades2.at(i)->collidingItems().empty() && !granades2.at(i)->collidesWithItem(player2)){
                if(granades2.at(i)->chocarWithEnemies(getEnemies(),getScene())){
                    score2++;
                    newExplotion2=new explotion();
                    newExplotion2->setPx(granades2.at(i)->getPx());
                    newExplotion2->setPy(granades2.at(i)->getPy()-40);
                    newExplotion2->setPos(newExplotion2->getPx(),newExplotion2->getPy());
                    explotions2.append(newExplotion2);
                    getScene()->addItem(newExplotion2);
                    lcd_score2->display(score2);
                    getScene()->removeItem(granades2.at(i));
                    granades2.removeAt(i);
                }
            }
            else{
              granades2.at(i)->mover();
            }

        }
    }

    for(int i=0;i<getEnemies().size();i++){
        if(!getEnemies().at(i)->collidingItems().empty()){
            if(getEnemies().at(i)->collidesWithItem(getScene()->getBordeIzquierdo())  || getEnemies().at(i)->collidesWithItem(player2)){
                if(getEnemies().at(i)->collidesWithItem(player2)){
                    if(numHealth2==0){
                        getScene()->removeItem(player2);
                    }
                    else{
                        numHealth2--;
                        lcd_health2->display(numHealth2);
                    }
                }
                getScene()->removeItem(getEnemies().at(i));
                getEnemies().removeAt(i);
            }
        }
        else{
            getEnemies().at(i)->moverE();
        }
    }


}

QList<granade *> level1Multiplayer::getGranades2() const
{
    return granades2;
}

void level1Multiplayer::setGranades2(const QList<granade *> &value)
{
    granades2 = value;
}

int level1Multiplayer::getScore2() const
{
    return score2;
}

void level1Multiplayer::setScore2(int value)
{
    score2 = value;
}

QList<bullet *> level1Multiplayer::getBullets2() const
{
    return bullets2;
}

void level1Multiplayer::setBullets2(const QList<bullet *> &value)
{
    bullets2 = value;
}

int level1Multiplayer::getNumHealth2() const
{
    return numHealth2;
}

void level1Multiplayer::setNumHealth2(int value)
{
    numHealth2 = value;
}

QLCDNumber *level1Multiplayer::getLcd_health2() const
{
    return lcd_health2;
}

void level1Multiplayer::setLcd_health2(QLCDNumber *value)
{
    lcd_health2 = value;
}

QLCDNumber *level1Multiplayer::getLcd_score2() const
{
    return lcd_score2;
}

void level1Multiplayer::setLcd_score2(QLCDNumber *value)
{
    lcd_score2 = value;
}


Jugador *level1Multiplayer::getPlayer2() const
{
    return player2;
}

void level1Multiplayer::setPlayer2(Jugador *value)
{
    player2 = value;
}

void level1Multiplayer::keyPressEvent(QKeyEvent *ev)
{
    //Player1
    if(ev->key()==Qt::Key_Escape){  //Tecla para dar la orden de cerrar la simulación
        close();
    }
    if(ev->key()==Qt::Key_A  && getPlayer()->getPx()>-100){
        getPlayer()->setVx(-15);
        getPlayer()->setVUnit(-1);
        setAjusteRifle(-15);
        setVUnitShot(-1);
        ev->accept();
    }
    if(ev->key()==Qt::Key_W){
        setFlagJump(true);
        ev->accept();
    }
    if(ev->key()==Qt::Key_D && getPlayer()->getPx()<990){
        getPlayer()->setVx(15);
        getPlayer()->setVUnit(1);
        setAjusteRifle(15);
        setVUnitShot(1);
        ev->accept();
    }
    if(ev->key()==Qt::Key_Space){
        setNewBullet(new bullet());
        getNewBullet()->setVUnit(getVUnitShot());
        getNewBullet()->setPx(getPlayer()->getPx()+getAjusteRifle());
        getNewBullet()->setPy(getPlayer()->getPy()+15);
        getNewBullet()->setPos(getNewBullet()->getPx(),getNewBullet()->getPy());
        bulletsAux.append(getNewBullet());
        setBullets(bulletsAux);
        getScene()->addItem(getNewBullet());
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
        if(numAvailableGranades2>0){
            setNewGranade(new granade());
            getNewGranade()->setPx(getPlayer()->getPx());
            getNewGranade()->setPy(getPlayer()->getPy());
            getNewGranade()->setPos(getNewGranade()->getPx(),getNewGranade()->getPy());
            getNewGranade()->setVUnit(getVUnitShot());
            granadesAux.append(getNewGranade());
            setGranades(granadesAux);
            getScene()->addItem(getNewGranade());
            numAvailableGranades2--;
        }
        ev->accept();
    }


    //Player2
    if(ev->key()==Qt::Key_Escape){  //Tecla para dar la orden de cerrar la simulación
        close();
    }
    if(ev->key()==Qt::Key_J  && player2->getPx()>-100){  //Tecla para dar la orden de cerrar la simulación
        player2->setVx(-15);
        player2->setVUnit(-1);
        ajusteRifle2=-15;
        vUnitShot2=-1;
        ev->accept();
    }
    if(ev->key()==Qt::Key_I){  //Tecla para dar la orden de cerrar la simulación
        flagJump2=true;
        ev->accept();
    }
    if(ev->key()==Qt::Key_L && player2->getPx()<990){  //Tecla para dar la orden de cerrar la simulación
        player2->setVx(15);
        player2->setVUnit(1);
        ajusteRifle2=15;
        vUnitShot2=1;
        ev->accept();
    }
    if(ev->key()==Qt::Key_P){
        newBullet2=new bullet();
        newBullet2->setVUnit(vUnitShot2);
        newBullet2->setPx(player2->getPx()+ajusteRifle2);
        newBullet2->setPy(player2->getPy()+15);
        newBullet2->setPos(newBullet2->getPx(),newBullet2->getPy());
        bullets2.append(newBullet2);
        getScene()->addItem(newBullet2);
        ev->accept();

    }
    if(ev->key()==Qt::Key_O){
        if(numAvailableGranades2>0){
            newGranade2=new granade();
            newGranade2->setPx(player2->getPx());
            newGranade2->setPy(player2->getPy());
            newGranade2->setPos(newGranade2->getPx(),newGranade2->getPy());
            newGranade2->setVUnit(vUnitShot2);
            granadesAux.append(newGranade2);
            granades2.append(newGranade2);
            getScene()->addItem(newGranade2);
            numAvailableGranades2--;
        }
        ev->accept();
    }


}

