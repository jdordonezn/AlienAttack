#include "myscene.h"


myscene::myscene(int x, int y, int w, int h)
{
    this->setSceneRect(x,y,w,h);
    bordeSuperior=new QGraphicsLineItem(-100,10,1040,10);
    bordeIzquierdo=new QGraphicsLineItem(-100,10,-100,620);
    bordeDerecho=new QGraphicsLineItem(1040,10,1040,620);
    bordeInferior=new QGraphicsLineItem(-100,620,1040,620);
    this->addItem(bordeSuperior);
    this->addItem(bordeIzquierdo);
    this->addItem(bordeDerecho);
    this->addItem(bordeInferior);
}

myscene::~myscene()
{
    delete bordeSuperior;
    delete bordeDerecho;
    delete bordeIzquierdo;
    delete bordeDerecho;
}

QGraphicsLineItem *myscene::getBordeIzquierdo() const
{
    return bordeIzquierdo;
}

QGraphicsLineItem *myscene::getBordeDerecho() const
{
    return bordeDerecho;
}

QGraphicsLineItem *myscene::getBordeInferior() const
{
    return bordeInferior;
}
