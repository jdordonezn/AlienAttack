#ifndef GRANADA_H
#define GRANADA_H
#include <bala.h>

class granada: public bala
{
public:
    granada(int _px, int _py);
    void mover();
    bool fueraDeRango();
private:
    double vx=50;
    double vy=-50;
    double ay=9.8;
    double dt=0.3;
};

#endif // GRANADA_H
