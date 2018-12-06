#ifndef GRANADE_H
#define GRANADE_H
#include <bullet.h>

class granade:public bullet
{
public:
    granade(QGraphicsItem* grnd=0);
    void mover();
    bool fueraDeRango();

    void setVUnit(int value);

private:
    double vx=50;
    double vy=-30;
    double ay=9.8;
    double dt=1;
    int vUnit=1;
};

#endif // GRANADE_H
