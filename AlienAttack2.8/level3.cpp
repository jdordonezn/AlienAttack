#include "level3.h"
#include "ui_level3.h"

level3::level3(QWidget *parent) :
    MainWindow (parent),
    ui(new Ui::level3)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(this->getScene());
    ui->graphicsView->setStyleSheet("background: transparent");
    this->setMovie(new QMovie(":/Pictures/fondo5.gif"));
    ui->label->setMovie(this->getMovie());
    this->getMovie()->start();
    setFlagLevel(3);
    setNumHealth(5);
    setLcd_score(ui->lcdsc1);
    setLcd_health(ui->lcdhl1);
    ui->lcdhl1->display(getNumHealth());
    getPlayer()->setFlagResbalar(0);        //Así no resbala
    getPlayer()->setCd(0.6);
    timerThrowE=new QTimer();
    connect(timerThrowE,SIGNAL(timeout()),this,SLOT(newThrowEnemy()));
    connect(getTimer(),SIGNAL(timeout()),this,SLOT(animarThrow()));
    timerThrowE->start(3000);
}

level3::~level3()
{
    delete ui;
}

void level3::newThrowEnemy()
{
    for(int i=0;i<getEnemies().size();i++){
            newEnemyThrow=new enemy();
            newEnemyThrow->setTypeAlien(4);
            newEnemyThrow->setVx(-5);
            newEnemyThrow->setDt(0.2);
            newEnemyThrow->setPx(getEnemies().at(i)->getPx());
            newEnemyThrow->setPy(getEnemies().at(i)->getPy()+200);
            newEnemyThrow->setPos(newEnemyThrow->getPx(),newEnemyThrow->getPy());
            enemiesThrow.append(newEnemyThrow);
            getScene()->addItem(newEnemyThrow);
    }
}

void level3::animarThrow(){


    for(int i=0;i<enemiesThrow.size();i++){

        if(enemiesThrow.at(i)->collidesWithItem(getScene()->getBordeIzquierdo())  || enemiesThrow.at(i)->collidesWithItem(getPlayer())){
                if(enemiesThrow.at(i)->collidesWithItem(getPlayer())){
                    if(getNumHealth()==0){
                        if(!getMultijugador()){
                            setMessage("GAME OVER :c");
                            SeeMsgScreen();
                        }
                        else{
                            getScene()->removeItem(getPlayer());
                        }
                     }
                     else{
                        setNumHealth(getNumHealth()-1);
                        getLcd_health()->display(getNumHealth());
                     }
                }
                getScene()->removeItem(enemiesThrow.at(i));
                enemiesThrow.removeAt(i);
            }

        else{
            enemiesThrow.at(i)->moverThrow(getScene()->getBordeInferior());
        }
    }


    for(int i=0;i<getBullets().size();i++){
        if(!getBullets().at(i)->collidingItems().empty() && !getBullets().at(i)->collidesWithItem(getPlayer())){
            if(!getBullets().at(i)->collidesWithItem(getScene()->getBordeIzquierdo()) && !getBullets().at(i)->collidesWithItem(getScene()->getBordeDerecho())){
                if(getBullets().at(i)->chocarWithEnemies(enemiesThrow,getScene())){
                    setScore(getScore()+1);
                    getLcd_score()->display(getScore());
                }
            }
            getScene()->removeItem(getBullets().at(i));
            getBullets().removeAt(i);
        }
        else{
            getBullets().at(i)->mover();
        }
    }
    for(int i=0;i<getGranades().size();i++){
        if(getGranades().at(i)->fueraDeRango()){
            getScene()->removeItem(getGranades().at(i));
            getGranades().removeAt(i);
        }
        else{
            if(!getGranades().at(i)->collidingItems().empty() && !getGranades().at(i)->collidesWithItem(getPlayer())){
                if(getGranades().at(i)->chocarWithEnemies(enemiesThrow,getScene())){
                    setScore(getScore()+1);
                    getLcd_score()->display(getScore());
                    newExplotionAux=new explotion();
                    newExplotionAux->setPx(getGranades().at(i)->getPx());
                    newExplotionAux->setPy(getGranades().at(i)->getPy()-40);
                    newExplotionAux->setPos(newExplotionAux->getPx(),newExplotionAux->getPy());
                    eplotionsAux.append(newExplotionAux);
                    setExplotions(eplotionsAux);
                    getScene()->addItem(newExplotionAux);
                    getScene()->removeItem(getGranades().at(i));
                    getGranades().removeAt(i);
                }
            }
            else{
              getGranades().at(i)->mover();
            }
        }
    }
}

QList<enemy *> level3::getEnemiesThrow() const
{
    return enemiesThrow;
}

void level3::setEnemiesThrow(const QList<enemy *> &value)
{
    enemiesThrow = value;
}


