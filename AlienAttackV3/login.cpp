#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    carry (parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

void login::consultar()
{
    QSqlQuery consulta;

    if(consulta.exec("SELECT * FROM users WHERE user='"+ui->luser->text()+"' AND password='"+ui->lpass->text()+"'")){
        while (consulta.next()) {
            userValido=true;
            if(consulta.value(2).toInt()==lvlReal){
                if(lvlReal==2){
                    if(multiplayer){
                        lv2M=new level2multiplayer();
                        lv2M->show();
                    }
                    else{
                        lv2=new level2();
                        lv2->show();
                    }
                }
                else if(lvlReal==3){
                    if(multiplayer){
                        lv3M=new level3multiplayer();
                        lv3M->show();
                    }
                    else{
                        lv3=new level3();
                        lv3->show();
                    }
                }
            }
        }
        if(!userValido){
          exp=new exeption();
          exp->show();
          //qDebug()<<"El usuario X ingresado es invalido";
        }
    }
}

login::~login()
{
    delete ui;
}

void login::on_pSend_clicked()
{
    consultar();
}

bool login::getMultiplayer() const
{
    return multiplayer;
}

void login::setMultiplayer(bool value)
{
    multiplayer = value;
}

int login::getLvlReal() const
{
    return lvlReal;
}

void login::setLvlReal(int value)
{
    lvlReal = value;
}
