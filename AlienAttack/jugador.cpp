#include "jugador.h"

Jugador::Jugador()
{

}

QRectF Jugador::boundingRect() const
{
     return QRectF(20,550-radio,radio,radio);
}

void Jugador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(20,500,50,50,QPixmap(":/Pictures/Sprites juego/derecha.png"));
    //painter->setBrush(Qt::blue);
    //painter->drawEllipse(boundingRect());
}


void Jugador::mover()
{
    setPos(px,py);
}

int Jugador::getPx() const
{
    return px;
}

void Jugador::setPx(int value)
{
    px = value;
}

int Jugador::getPy() const
{
    return py;
}

void Jugador::setPy(int value)
{
    py = value;
}

void Jugador::salto()
{
    vy=vy+ay*dt;
    py=py+(vy*dt)+(0.5*ay*dt*dt);
}

void Jugador::setVy(double value)
{
    vy = value;
}

double Jugador::getVy() const
{
    return vy;
}


