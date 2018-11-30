#include "granada.h"

granada::granada(int _px, int _py):bala(_px,_py)
{
}

void granada::mover()
{
    vy=vy+ay*dt;
    this->setPx(this->getPx()+vx*dt);
    this->setPy(this->getPy()+(vy*dt)+(0.5*ay*dt*dt));
    setPos(this->getPx(),this->getPy());
}

bool granada::fueraDeRango()
{
    if((this->getPx()<0 || this->getPx()>980) || ((this->getPy()>0 || this->getPy()<(-560)))){
        return true;
    }
    else{
        return false;
    }
}
