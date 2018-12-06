#include "enemy.h"

enemy::enemy(QGraphicsItem* enem):Jugador(enem)
{
    setPixmap(QPixmap(":/Pictures/alien51.gif"));
}

void enemy::moverE()
{
    if(cont<5){
        setPixmap(QPixmap(":/Pictures/alien51.gif"));
    }
    else{
        setPixmap(QPixmap(":/Pictures/alien52.gif"));
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

