#ifndef EXPLOTION_H
#define EXPLOTION_H
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QObject>

class explotion:public QObject,
                public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explotion(QGraphicsItem* expl = 0);
    void fotograma();

    int getPx() const;
    void setPx(int value);

    int getPy() const;
    void setPy(int value);


    int getCont() const;
    void setCont(int value);

private:
    int px;
    int py;
    int cont=0;
};

#endif // EXPLOTION_H
