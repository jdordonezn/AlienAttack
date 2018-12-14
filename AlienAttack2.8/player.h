#ifndef JUGADOR_H
#define JUGADOR_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <math.h>


class Jugador:public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador(QGraphicsItem* jug = 0);
//    QRectF boundingRect() const;
    ~Jugador();
//    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mover();

    int getPx() const;
    void setPx(int value);

    int getPy() const;
    void setPy(int value);

    void salto();


    int getVx() const;
    void setVx(int value);

    double getCd() const;
    void setCd(double value);

    int getVUnit() const;
    void setVUnit(int value);

    int getVy() const;
    void setVy(int value);

    int getFlagResbalar() const;
    void setFlagResbalar(int value);

    bool getPlayerMan() const;
    void setPlayerMan(bool value);

    bool getLoad() const;
    void setLoad(bool value);

private:
    int px=-100;
    int py=575;
    int radio=50;
    int vx=0;
    int vy=-50;
    int ax;
    int masa=10;
    int vUnit=1;
    int cont=0;
    double cd;
    double ay=9.8;
    double dt=0.3;
    int flagResbalar=0;
    bool playerMan=false;
    bool load=false;
};


#endif // JUGADOR_H
