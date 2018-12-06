#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QObject>
#include <enemy.h>
#include <myscene.h>

class bullet:public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet(QGraphicsItem* bulled = 0);
    ~bullet();
    void mover();
    bool fuerdaDeRango();
    bool chocarWithEnemies(QList<enemy*> _enemies,myscene* _scene);



    int getVUnit() const;
    void setVUnit(int value);

    int getPx() const;
    void setPx(int value);

    int getPy() const;
    void setPy(int value);

private:
    int px;
    int py;
    int vx=20;
    int vUnit;
};

#endif // BULLET_H
