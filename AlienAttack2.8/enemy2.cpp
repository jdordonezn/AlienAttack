#include "enemy2.h"


enemy2::enemy2(QGraphicsItem *enem):enemy (enem)
{
    setPixmap(QPixmap(":/Pictures/alien31.gif"));
}

void enemy2::moverE(QGraphicsItem* _bordeInferior)
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
