#include "granade.h"

granade::granade(QGraphicsItem *grnd):bullet (grnd)
{
    setPixmap(QPixmap(":/Pictures/granade.gif"));
}

void granade::mover()
{
    vy=vy+(ay*dt);
    this->setPx(this->getPx()+(vx*vUnit*dt));
    this->setPy(this->getPy()+(vy*dt)+(0.5*ay*dt*dt));
    setPos(this->getPx(),this->getPy());
}

bool granade::fueraDeRango()
{
    if((this->getPx()<-990 || this->getPx()>1020) || ((this->getPy()<0 || this->getPy()>610))){
        return true;
    }
    else{
        return false;
    }

}


void granade::setVUnit(int value)
{
    vUnit = value;
}
