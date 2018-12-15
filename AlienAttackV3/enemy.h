#ifndef ENEMY_H
#define ENEMY_H
#include <player.h>
#include <myscene.h>


class enemy:public Jugador
{
public:
    enemy(QGraphicsItem* enem=0);
    void moverE();
    void throwAlien(QList<enemy*> _enemies,myscene* _scene);
    int getPx() const;
    void setPx(int value);

    int getPy() const;
    void setPy(int value);

    int getVx() const;
    void setVx(int value);

    int getTypeAlien() const;
    void setTypeAlien(int value);
    void moverThrow(QGraphicsItem* _bordeInferior);

    double getDt() const;
    void setDt(double value);





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

#endif // ENEMY_H
