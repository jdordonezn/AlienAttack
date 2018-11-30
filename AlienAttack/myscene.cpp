#include "myscene.h"


myscene::myscene(int x, int y, int w, int h)
{
    this->setSceneRect(x,y,w,h);
    bordeSuperior=new QGraphicsLineItem(0,10,1000,10);
    bordeIzquierdo=new QGraphicsLineItem(0,10,0,570);
    bordeDerecho=new QGraphicsLineItem(1000,10,1000,570);
    bordeInferior=new QGraphicsLineItem(0,570,1000,570);
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
