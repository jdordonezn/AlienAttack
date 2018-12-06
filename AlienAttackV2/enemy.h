#ifndef ENEMY_H
#define ENEMY_H
#include <player.h>

class enemy:public Jugador
{
public:
    enemy(QGraphicsItem* enem=0);
    void moverE();
    int getPx() const;
    void setPx(int value);

    int getPy() const;
    void setPy(int value);

private:
    int vx=-5;
    int px=900;
    int py=535;
    int cont=0;
    int dt=1;
};

#endif // ENEMY_H
