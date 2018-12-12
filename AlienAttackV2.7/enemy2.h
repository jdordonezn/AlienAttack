#ifndef ENEMY2_H
#define ENEMY2_H
#include <enemy.h>

class enemy2:public enemy
{
public:
    enemy2(QGraphicsItem* enem=0);
    void moverE(QGraphicsItem* _bordeInferior);
private:
    int vy=10;
    int vx=-5;
    int px=900;
    int py=535;
    int cont=0;
    double dt=1.0;
    int typeAlien=1;
    double v;
    int masa=5;
    double e=0.7;                   //coeficiente de restitución
    double cd=0.01;                 //coeficiente de fricción
    int g=10;                       //constante gravitacional
    double ax;                      //Aceleración en x
    double ay;                      //Aceleración en y
    double teta;                    //Angulo del movimiento
    int p=1;                        //Densidad del fluido

};

#endif // ENEMY2_H
