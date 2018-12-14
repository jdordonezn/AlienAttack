#include "enemy.h"

enemy::enemy(QGraphicsItem* enem):Jugador(enem)
{
    setPixmap(QPixmap(":/Pictures/alien51.gif"));
}

void enemy::moverE()
{
    if(cont<5){
        switch (typeAlien) {
            case 1:
                setPixmap(QPixmap(":/Pictures/alien51.gif"));
                break;
            case 2:
                setPixmap(QPixmap(":/Pictures/Alien1.gif"));
                break;
            case 3:
                setPixmap(QPixmap(":/Pictures/UFO.gif"));
                break;
            default:
                setPixmap(QPixmap(":/Pictures/alien31.gif"));
                break;
        }

    }
    else{
        switch (typeAlien) {
            case 1:
                setPixmap(QPixmap(":/Pictures/alien52.gif"));
                break;
            case 2:
                setPixmap(QPixmap(":/Pictures/Alien2.gif"));
                break;
            case 3:
                setPixmap(QPixmap(":/Pictures/UFO.gif"));
                break;
            default:
                setPixmap(QPixmap(":/Pictures/alien32.gif"));
                break;
        }
        if(cont==9){
            cont=0;
        }
    }
    cont++;
    px=px+(vx*dt);
    setPos(px,py);
}

void enemy::throwAlien(QList<enemy *> _enemies, myscene *_scene)
{


}


int enemy::getPx() const
{
    return px;
}

void enemy::setPx(int value)
{
    px = value;
}

int enemy::getPy() const
{
    return py;
}

void enemy::setPy(int value)
{
    py = value;
}

int enemy::getVx() const
{
    return vx;
}

void enemy::setVx(int value)
{
    vx = value;
}

int enemy::getTypeAlien() const
{
    return typeAlien;
}

void enemy::setTypeAlien(int value)
{
    typeAlien = value;
}



void enemy::moverThrow(QGraphicsItem* _bordeInferior)
{
    //Parte grafica
    if(cont<5){
        setPixmap(QPixmap(":/Pictures/alien31.gif"));
    }
    else{
        setPixmap(QPixmap(":/Pictures/alien32.gif"));
        if(cont==9){cont=0;}
    }
    cont++;
    //Colisión con el suelo
    if(collidesWithItem(_bordeInferior)){
        vy=-e*vy;
    }
    //Ecuaciones de movimiento
    teta=atan2(vx,vy);
    v=sqrt(pow(vx,2)+pow(vy,2));
    ax=(p*pow(v,2)*cd*cos(teta))/(2*masa);
    ay=((p*pow(v,2)*cd*sin(teta))/(2*masa))+g;
    vx=vx+(ax*dt);
    vy=vy+(ay*dt);
    px=px+(vx*dt)+((ax*pow(dt,2))/2);
    py=py+(vy*dt)+((ay*pow(dt,2))/2);
    setPos(px,py);
}

double enemy::getDt() const
{
    return dt;
}

void enemy::setDt(double value)
{
    dt = value;
}


