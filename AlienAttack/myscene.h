#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
class myscene: public QGraphicsScene
{
public:
    myscene(int x, int y, int w, int h);
    ~myscene();
private:
    QGraphicsLineItem* bordeSuperior;
    QGraphicsLineItem* bordeIzquierdo;
    QGraphicsLineItem* bordeDerecho;
    QGraphicsLineItem* bordeInferior;
};

#endif // MYSCENE_H
