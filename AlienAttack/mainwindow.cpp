#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new myscene(0,0,1000,580);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background: transparent");
    movie=new QMovie(":/Pictures/Sprites juego/fondos/fondo.gif");
    ui->label->setMovie(movie);
    movie->start();
    ui->lcd->display(numHealth);
    ui->lcd1->display(score);

    //ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Pictures/Sprites juego/fondo1.png")));
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    crearEnemy=new QTimer();
    connect(crearEnemy,SIGNAL(timeout()),this,SLOT(nuevoEnemy()));

    timer->start(35);
    crearEnemy->start(2000);
    jugador=new Jugador();
    scene->addItem(jugador);

    gunSound = new QMediaPlayer();
    gunSound->setMedia(QUrl(":/sounds/gun.wav"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_Escape){  //Tecla para dar la orden de cerrar la simulación
        close();
    }
    if(ev->key()==Qt::Key_A  && jugador->getPx()>0){  //Tecla para dar la orden de cerrar la simulación
        jugador->setPx(jugador->getPx()-5);
        ev->accept();
    }
    if(ev->key()==Qt::Key_W){  //Tecla para dar la orden de cerrar la simulación
        flagJump=true;
        ev->accept();
    }
    if(ev->key()==Qt::Key_D && jugador->getPx()<980){  //Tecla para dar la orden de cerrar la simulación
        jugador->setPx(jugador->getPx()+5);
        ev->accept();
    }
    if(ev->key()==Qt::Key_Space){
        newBala=new bala(jugador->getPx(),jugador->getPy());
        balas.append(newBala);
        scene->addItem(newBala);
        ev->accept();

        /*if(gunSound->state() == QMediaPlayer::PlayingState){
            gunSound->setPosition(0);
        }
        */
        //if (gunSound->state() == QMediaPlayer::StoppedState) {
            gunSound->play();
        //}
    }
    if(ev->key()==Qt::Key_C){
        newGranada=new granada(jugador->getPx(),jugador->getPy());
        granadas.append(newGranada);
        scene->addItem(newGranada);
        ev->accept();
    }
}

void MainWindow::animar(){

    if(flagJump && jugador->getPy()<=0){
        jugador->salto();
    }
    else{
        jugador->setPy(0);
        jugador->setVy(-60);
        flagJump=false;
    }
    for(int i=0;i<balas.size();i++){
        if(balas.at(i)->fueraDeRango()){
            scene->removeItem(balas.at(i));
            balas.removeAt(i);
        }
        else{
            balas.at(i)->mover();
        }
    }
    for(int i=0;i<granadas.size();i++){
        if(granadas.at(i)->fueraDeRango()){
            scene->removeItem(granadas.at(i));
            granadas.removeAt(i);
        }
        else{
            granadas.at(i)->mover();
        }
    }

    for(int i=0;i<enemies.size();i++){

        if(!enemies.at(i)->collidingItems().empty()){
            if(!jugador->collidingItems().empty()){
               if(numHealth==0){
                   close();
               }
               else{
                   numHealth--;
                   ui->lcd->display(numHealth);
               }
            }
            else{
                ++score;
                ui->lcd1->display(score);
            }
            scene->removeItem(enemies.at(i));
            enemies.removeAt(i);
        }
        else{
            enemies.at(i)->moverE();
        }
    }

    jugador->mover();
}

void MainWindow::nuevoEnemy()
{
    newEnemy=new enemy();
    enemies.append(newEnemy);
    scene->addItem(newEnemy);

}


