#ifndef ENEMY_H
#define ENEMY_H
#include <jugador.h>

class enemy:public Jugador
{
public:
    enemy();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void moverE();
private:
    int vx=-5;
    int cont=0;
};

#endif // ENEMY_H
