#include "bala.h"


bala::bala(double _px, double _py){
    this->px=_px;
    this->py=_py;
}

QRectF bala::boundingRect() const
{
    return QRectF(0,550,radio,radio);
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void bala::mover()
{
    px=px+vx;
    setPos(px,py);
}

double bala::getPx() const
{
    return px;
}

void bala::setPx(double value)
{
    px = value;
}

bool bala::fueraDeRango()
{
    if((px<0 || px>980)){
        return true;
    }
    else{
        return false;
    }
}

double bala::getPy() const
{
    return py;
}

void bala::setPy(double value)
{
    py = value;
}


