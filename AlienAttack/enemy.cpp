#include "enemy.h"

enemy::enemy():Jugador ()
{
    setVy(-35);
    setPx(0);
    setPy(0);
}

QRectF enemy::boundingRect() const
{
    return QRectF(935,480,60,60);
}

void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(935,480,60,60,QPixmap(":/Pictures/Sprites juego/alien5.gif"));
}

void enemy::moverE()
{

    if(cont<10){
        this->setPx(this->getPx()+vx);
    }
    else{
        this->salto();
        if(cont==50 || getPy()>0){
            setPy(0);
            cont=0;
        }
    }
    setPos(this->getPx(),this->getPy());
    cont++;
}

