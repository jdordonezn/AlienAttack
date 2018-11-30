#ifndef JUGADOR_H
#define JUGADOR_H
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsPixmapItem>

class Jugador:public QGraphicsItem
{
public:
    Jugador();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mover();

    int getPx() const;
    void setPx(int value);

    int getPy() const;
    void setPy(int value);

    void salto();
    void setVy(double value);
    double getVy() const;

private:
    int px=0;
    int py=0;
    int radio=50;
    int vx=30;
    double vy=-60;
    int ax;
    double ay=9.8;
    double dt=0.3;
};


#endif // JUGADOR_H
