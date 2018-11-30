#ifndef BALA_H
#define BALA_H
#include <QGraphicsItem>
#include <QPainter>

class bala:public QGraphicsItem
{
public:
    bala(double _px, double _py);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    double getPx() const;
    void setPx(double value);
    bool fueraDeRango();
    double getPy() const;
    void setPy(double value);

private:
    double px=0;
    double py=0;
    double vx=20;
    int radio=10;
};

#endif // BALA_H
