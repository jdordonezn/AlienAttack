#include "enemy.h"

enemy::enemy(QGraphicsItem* enem):Jugador(enem)
{
    setPixmap(QPixmap(":/Pictures/alien51.gif"));
}

void enemy::moverE()
{
    if(cont<5){
        if(typeAlien==1){
            setPixmap(QPixmap(":/Pictures/alien51.gif"));
        }
        else {
            setPixmap(QPixmap(":/Pictures/Alien1.gif"));
        }

    }
    else{
        if(typeAlien==1){
            setPixmap(QPixmap(":/Pictures/alien52.gif"));
        }
        else {
            setPixmap(QPixmap(":/Pictures/Alien2.gif"));
        }
        if(cont==9){
            cont=0;
        }
    }
    cont++;
    px=px+(vx*dt);
    setPos(px,py);
}

int enemy::getPx() const
{
    return px;
}

void enemy::setPx(int value)
{
    px = value;
}

int enemy::getPy() const
{
    return py;
}

void enemy::setPy(int value)
{
    py = value;
}

int enemy::getVx() const
{
    return vx;
}

void enemy::setVx(int value)
{
    vx = value;
}

int enemy::getTypeAlien() const
{
    return typeAlien;
}

void enemy::setTypeAlien(int value)
{
    typeAlien = value;
}

