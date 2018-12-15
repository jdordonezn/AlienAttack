#include "carry.h"
#include "ui_carry.h"


carry::carry(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::carry)
{
    ui->setupUi(this);
    QString nombre;
    nombre.append("BDGame.sqlite"); //crea base de datos

    db = QSqlDatabase::addDatabase("QSQLITE"); //agregar tipo de driver de base de datos
    db.setDatabaseName(nombre);

    db.open(); //abrir base de datos (se cra en el build)

    if(db.open()){ //si se creó la base de datos
        qDebug()<<"Se ha conectado a la base de datos.";
    } else {
        qDebug()<<"ERROR! NO se ha conectado a la base de datos.";
    }
    createTables();


}

void carry::createTables()
{
    QString tableUser;
    tableUser.append("CREATE TABLE IF NOT EXISTS users("
                    "user VARCHAR(10) PRIMARY KEY,"
                    "password VARCHAR(10) NOT NULL,"
                    "level INTEGER NOT NULL"
                    ");");
    QSqlQuery createTableUser;
    createTableUser.prepare(tableUser);
    if(createTableUser.exec()){ //si se crea la tabla correctamente
        qDebug()<<"Se conecto con la tabla de usuarios";
    } else {
        qDebug()<<"No fue posible hacer conexión con la tabla usuarios";
        qDebug()<<"ERROR! "<<createTableUser.lastError(); //para mostrar el tipo de error
    }
}

void carry::insertCredential()
{
    QSqlQuery del;
    del.exec("DELETE FROM users WHERE user='"+ui->luser->text()+"'");
    QSqlQuery insertar;
    if(insertar.exec("INSERT INTO users(user,password,level) VALUES('"+ui->luser->text()+"','"+ui->lpassw->text()+"',"+QString::number(lvl)+")")){
        qDebug()<<"Las credenciales se han insertado.";
    }
    else{
        qDebug()<<"Las credenciales NO se han insertado.";
    }
}


carry::~carry()
{
    delete ui;
}


void carry::on_pSave_clicked()
{
    insertCredential();
    close();
    close();
}

int carry::getLvl() const
{
    return lvl;
}

void carry::setLvl(int value)
{
    lvl = value;
}
