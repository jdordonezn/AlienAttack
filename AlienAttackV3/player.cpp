#include "player.h"

Jugador::Jugador(QGraphicsItem* jug):QGraphicsPixmapItem(jug)
{
    setPixmap(QPixmap(":/Pictures/derecha.png"));
}

Jugador::~Jugador()
{

}

void Jugador::mover()
{
    if(vx==0 || flagResbalar==1){
        if(vUnit==1){
            if(playerMan){
                setPixmap(QPixmap(":/Pictures/hderecha.gif"));
            }
            else{
                setPixmap(QPixmap(":/Pictures/derecha.png"));
            }
        }
        else{
            if(playerMan){
               setPixmap(QPixmap(":/Pictures/hizquierda.gif"));
            }
            else{
                setPixmap(QPixmap(":/Pictures/izquierda.png"));
            }
        }

    }
    else{
        if(vUnit==1){
            if(cont<5){
                if(playerMan){ setPixmap(QPixmap(":/Pictures/hderecha1.gif"));}
                else{
                    setPixmap(QPixmap(":/Pictures/derecha1.gif"));
                }
            }
            else{
                if(playerMan){setPixmap(QPixmap(":/Pictures/hderecha2.gif"));}
                else{
                     setPixmap(QPixmap(":/Pictures/derecha2.gif"));
                }
                if(cont==10){
                    cont=0;
                }
            }
        }
        else{
            if(cont<5){
                if(playerMan){setPixmap(QPixmap(":/Pictures/hizquierda1.gif"));}
                else{
                    setPixmap(QPixmap(":/Pictures/izquierda1.gif"));
                }
            }
            else{
                if(playerMan){setPixmap(QPixmap(":/Pictures/hizquierda2.gif"));}
                else{
                    setPixmap(QPixmap(":/Pictures/izquierda2.gif"));

                }
                if(cont==10){
                    cont=0;
                }
            }
        }
        cont++;

    }

    vx=vx*exp(-(cd/masa)*dt);
    px=px+(vx*dt);
    if(px<-100){
        setPos(-100,py);
    }
    else if(px>1020){
        setPos(1020,py);
    }
    else{
        setPos(px,py);
    }

}

int Jugador::getPx() const
{
    return px;
}

void Jugador::setPx(int value)
{
    px = value;
}

int Jugador::getPy() const
{
    return py;
}

void Jugador::setPy(int value)
{
    py = value;
}

void Jugador::salto()
{
    vy=vy+ay*dt;
    py=py+(vy*dt)+(0.5*ay*dt*dt);
}


int Jugador::getVx() const
{
    return vx;
}

void Jugador::setVx(int value)
{
    vx = value;
}


double Jugador::getCd() const
{
    return cd;
}

void Jugador::setCd(double value)
{
    cd = value;
}

int Jugador::getVUnit() const
{
    return vUnit;
}

void Jugador::setVUnit(int value)
{
    vUnit = value;
}

int Jugador::getVy() const
{
    return vy;
}

void Jugador::setVy(int value)
{
    vy = value;
}

int Jugador::getFlagResbalar() const
{
    return flagResbalar;
}

void Jugador::setFlagResbalar(int value)
{
    flagResbalar = value;
}

bool Jugador::getPlayerMan() const
{
    return playerMan;
}

void Jugador::setPlayerMan(bool value)
{
    playerMan = value;
}

bool Jugador::getLoad() const
{
    return load;
}

void Jugador::setLoad(bool value)
{
    load = value;
}

