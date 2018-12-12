#include "bullet.h"


bullet::bullet(QGraphicsItem *bulled):QGraphicsPixmapItem(bulled)
{
    setPixmap(QPixmap(":/Pictures/bala1.png"));
}


void bullet::mover()
{
    px=px+(vUnit*vx);
    setPos(px,py);
}

bool bullet::fuerdaDeRango()
{
    if((this->getPx()<-70 || this->getPx()>900)){
        return true;
    }
    else{
        return false;
    }
}


bool bullet::chocarWithEnemies(QList<enemy*> _enemies,myscene* _scene)
{
    for(int i=0;i<_enemies.size();i++){
        if(collidesWithItem(_enemies.at(i))){
            _scene->removeItem(_enemies.at(i));
            _enemies.removeAt(i);
            return true;
        }
    }
    return false;
}


int bullet::getVUnit() const
{
    return vUnit;
}

void bullet::setVUnit(int value)
{
    vUnit = value;
}

int bullet::getPx() const
{
    return px;
}

void bullet::setPx(int value)
{
    px = value;
}

int bullet::getPy() const
{
    return py;
}

void bullet::setPy(int value)
{
    py = value;
}

bullet::~bullet()
{

}
