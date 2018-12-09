#include "explotion.h"

explotion::explotion(QGraphicsItem *expl):QGraphicsPixmapItem(expl)
{
    setPixmap(QPixmap(":/Pictures/explosion1.gif"));
}

void explotion::fotograma()
{
    if(cont<3){
        setPixmap(QPixmap(":/Pictures/explosion1.gif"));
    }
    else{
        setPixmap(QPixmap(":/Pictures/explosion2.gif"));
    }
    cont++;
}



int explotion::getPx() const
{
    return px;
}

void explotion::setPx(int value)
{
    px = value;
}

int explotion::getPy() const
{
    return py;
}

void explotion::setPy(int value)
{
    py = value;
}

int explotion::getCont() const
{
    return cont;
}

void explotion::setCont(int value)
{
    cont = value;
}

