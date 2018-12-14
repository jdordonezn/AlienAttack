#include "optsave.h"
#include "ui_optsave.h"


optSave::optSave(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::optSave)
{
    ui->setupUi(this);
    ui->graphicsView->setStyleSheet("background: transparent");
    movie=new QMovie("://Pictures/giphy.gif");
    ui->label_2->setMovie(movie);
    movie->start();


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

optSave::~optSave()
{
    delete ui;
}

void optSave::createTables()
{

    QString tableGeneral;
    QString tablePlayer;
    QString tableEnemies;
    tablePlayer.append("CREATE TABLE IF NOT EXISTS player("
                    "id INTEGER PRIMARY KEY,"
                    "px INTEGER NOT NULL,"
                    "py INTEGER NOT NULL,"
                    "vx INTEGER NOT NULL,"
                    "vy INTEGER NOT NULL,"
                    "flagResbalar INTEGER NOT NULL,"
                    "vUnit INTEGER NOT NULL"
                    ");");
    tableEnemies.append("CREATE TABLE IF NOT EXISTS enemies("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "px INTEGER NOT NULL,"
                    "py INTEGER NOT NULL"
                    ");");
    tableGeneral.append("CREATE TABLE IF NOT EXISTS general("
                    "id INTEGER PRIMARY KEY,"
                    "score INTEGER NOT NULL,"
                    "health INTEGER NOT NULL"
                     ");");

    QSqlQuery createTablePlayer;
    createTablePlayer.prepare(tablePlayer);

    if(createTablePlayer.exec()){ //si se crea la tabla correctamente
        qDebug()<<"La tabla de Player existe o se ha creado correctamente.";
    } else {
        qDebug()<<"La tabla de Player NO existe o NO se ha creado correctamente.";
        qDebug()<<"ERROR! "<<createTablePlayer.lastError(); //para mostrar el tipo de error
    }
    QSqlQuery createTableEnemies;
    createTableEnemies.prepare(tableEnemies);

    if(createTableEnemies.exec()){ //si se crea la tabla correctamente
        qDebug()<<"La tabla de Enemies existe o se ha creado correctamente.";
    } else {
        qDebug()<<"La tabla de Enemies NO existe o NO se ha creado correctamente.";
        qDebug()<<"ERROR! "<<createTableEnemies.lastError(); //para mostrar el tipo de error
    }
    QSqlQuery createTableGeneral;
    createTableGeneral.prepare(tableGeneral);

    if(createTableGeneral.exec()){ //si se crea la tabla correctamente
        qDebug()<<"La tabla General se ha creado correctamente.";
    } else {
        qDebug()<<"La tabla General NO existe o NO se ha creado correctamente.";
        qDebug()<<"ERROR! "<<createTableEnemies.lastError(); //para mostrar el tipo de error
    }

}

void optSave::insertDates()
{

    //Borrar información antigua de la tabla
    QSqlQuery query1;
    query1.exec("DELETE FROM player");
    //Inserción de nuevos datos a la tabla
    QSqlQuery query;
    if(query.exec("INSERT INTO player(id,px,py,vx,vy,flagResbalar,vUnit) VALUES (1,"
                  +QString::number(player->getPx())+","
                  +QString::number(player->getPy())+","
                  +QString::number(player->getVx())+","
                  +QString::number(player->getVy())+","
                  +QString::number(player->getFlagResbalar())+","
                  +QString::number(player->getVUnit())+""
                  ")")){ //si se crea la tabla correctamente
        qDebug()<<"Los datos del player se ha registrado.";
    } else {
        qDebug()<<"Los datos del player no se han registrado.";
        qDebug()<<"ERROR! "<<query.lastError(); //para mostrar el tipo de error
    }
    query1.exec("DELETE FROM general");
    //Inserción de nuevos datos a la tabla
    if(query.exec("INSERT INTO general(id,score,health) VALUES (1,"
                  +QString::number(lcd_s1->value())+","
                  +QString::number(lcd_h1->value())+""
                  ")")){ //si se crea la tabla correctamente
        qDebug()<<"Los datos Generales se han registrado.";
    } else {
        qDebug()<<"Los datos Generales no se han registrado.";
        qDebug()<<"ERROR! "<<query.lastError(); //para mostrar el tipo de error
    }

    query1.exec("DELETE FROM enemies");
    for(int i=0;i<enemies.size();i++){
        if(query.exec("INSERT INTO enemies(px,py) VALUES ("
                      +QString::number(enemies.at(i)->getPx())+","
                      +QString::number(enemies.at(i)->getPy())+""
                      ")")){ //si se crea la tabla correctamente
            qDebug()<<"Los datos de los Enemies se han registrado.";
        } else {
            qDebug()<<"Los datos de los Enemies no se han registrado.";
            qDebug()<<"ERROR! "<<query.lastError(); //para mostrar el tipo de error
        }
    }
}

void optSave::insertDatesMultiplayer()
{
    //Borrar información antigua de la tabla
    QSqlQuery query1;
    query1.exec("DELETE FROM player");
    //Inserción de nuevos datos a la tabla
    QSqlQuery query;
    if(query.exec("INSERT INTO player(id,px,py,vx,vy,flagResbalar,vUnit) VALUES (1,"
                  +QString::number(player->getPx())+","
                  +QString::number(player->getPy())+","
                  +QString::number(player->getVx())+","
                  +QString::number(player->getVy())+","
                  +QString::number(player->getFlagResbalar())+","
                  +QString::number(player->getVUnit())+""
                  ")")){ //si se crea la tabla correctamente
        qDebug()<<"Los datos del player 1 se ha registrado.";
    } else {
        qDebug()<<"Los datos del player 1 no se han registrado.";
        qDebug()<<"ERROR! "<<query.lastError(); //para mostrar el tipo de error
    }
    if(query.exec("INSERT INTO player(id,px,py,vx,vy,flagResbalar,vUnit) VALUES (2,"
                  +QString::number(player2->getPx())+","
                  +QString::number(player2->getPy())+","
                  +QString::number(player2->getVx())+","
                  +QString::number(player2->getVy())+","
                  +QString::number(player2->getFlagResbalar())+","
                  +QString::number(player2->getVUnit())+""
                  ")")){ //si se crea la tabla correctamente
        qDebug()<<"Los datos del player 2 se ha registrado.";
    } else {
        qDebug()<<"Los datos del player 2 no se han registrado.";
        qDebug()<<"ERROR! "<<query.lastError(); //para mostrar el tipo de error
    }

    query1.exec("DELETE FROM general");
    //Inserción de nuevos datos a la tabla
    if(query.exec("INSERT INTO general(id,score,health) VALUES (1,"
                  +QString::number(lcd_s1->value())+","
                  +QString::number(lcd_h1->value())+""
                  ")")){ //si se crea la tabla correctamente
        qDebug()<<"Los datos Generales del Jugador 1 se han registrado.";
    } else {
        qDebug()<<"Los datos Generales del Jugador 1 no se han registrado.";
        qDebug()<<"ERROR! "<<query.lastError(); //para mostrar el tipo de error
    }
    if(query.exec("INSERT INTO general(id,score,health) VALUES (2,"
                  +QString::number(lcd_s2->value())+","
                  +QString::number(lcd_h2->value())+""
                  ")")){ //si se crea la tabla correctamente
        qDebug()<<"Los datos Generales del Jugador 2 se han registrado.";
    } else {
        qDebug()<<"Los datos Generales del Jugador 2 no se han registrado.";
        qDebug()<<"ERROR! "<<query.lastError(); //para mostrar el tipo de error
    }


    query1.exec("DELETE FROM enemies");
    for(int i=0;i<enemies.size();i++){
        if(query.exec("INSERT INTO enemies(px,py) VALUES ("
                      +QString::number(enemies.at(i)->getPx())+","
                      +QString::number(enemies.at(i)->getPy())+""
                      ")")){ //si se crea la tabla correctamente
            qDebug()<<"Los datos de los Enemies se han registrado.";
        } else {
            qDebug()<<"Los datos de los Enemies no se han registrado.";
            qDebug()<<"ERROR! "<<query.lastError(); //para mostrar el tipo de error
        }
    }
}

void optSave::LoadDates()
{
    numEnemies=enemies.size();
    //qDebug()<<"Se cargaron "+QString::number(numEnemies)+"enemies";
    //Cargar información del jugador a partir de la tabla player
    QSqlQuery query2;
    //enem=new enemy();

    if(query2.exec("SELECT * FROM player WHERE id=1 LIMIT 1")){
        while (query2.next()){
            player->setPx(query2.value(1).toInt());
            player->setPy(query2.value(2).toInt());
            player->setVx(query2.value(3).toInt());
            player->setVy(query2.value(4).toInt());
            player->setFlagResbalar(query2.value(5).toInt());
            player->setVUnit(query2.value(6).toInt());
        }
        qDebug()<<"Se ha cargado los datos del Jugador 1";

    } else {
        qDebug()<<"No se ha cargado los datos del Jugador 1";
        qDebug()<<"ERROR! "<<query2.lastError(); //para mostrar el tipo de error
    }

    if(query2.exec("SELECT * FROM general WHERE id=1 LIMIT 1")){
        while (query2.next()){
            lcd_s1->display(query2.value(1).toInt());
            lcd_h1->display(query2.value(2).toInt());
        }
        qDebug()<<"Se ha cargado los datos Generales";

    } else {
        qDebug()<<"No se ha cargado los datos Generales";
        qDebug()<<"ERROR! "<<query2.lastError(); //para mostrar el tipo de error
    }


    if(query2.exec("SELECT * FROM enemies")){
        enem=new enemy();
        //enemies = new enemy();

        while (query2.next()){
            if(numEnemies>cont){
                enemies.at(cont)->setPx(query2.value(1).toInt());
                enemies.at(cont)->setPy(query2.value(2).toInt());
            }
            else{
                enem->setPx(query2.value(1).toInt());
                enem->setPy(query2.value(2).toInt());
                //enemies.insert(cont,enem);
                enemies.append(enem);
            }
            qDebug()<<"Enemi px:"+QString::number(query2.value(1).toInt())+",py:"+QString::number(query2.value(1).toInt())+".";
            qDebug()<<"No se ha cargado los datos del Jugador 1";

            cont++;
        }

        qDebug()<<"Se han cargado # ENEMIES"+QString::number(enemies.size())+".";

    } else {
        qDebug()<<"No se ha cargado los datos de Enemies";
        qDebug()<<"ERROR! "<<query2.lastError(); //para mostrar el tipo de error
    }
}

void optSave::LoadDatesMultiplayer()
{
    //Cargar información del jugador a partir de la tabla player
    QSqlQuery query2;

    if(query2.exec("SELECT * FROM player WHERE id=1 LIMIT 1")){
        while (query2.next()){
            player->setPx(query2.value(1).toInt());
            player->setPy(query2.value(2).toInt());
            player->setVx(query2.value(3).toInt());
            player->setVy(query2.value(4).toInt());
            player->setFlagResbalar(query2.value(5).toInt());
            player->setVUnit(query2.value(6).toInt());

        }
        qDebug()<<"Se ha cargado los datos del Juagdor 1";

    } else {
        qDebug()<<"No se ha cargado los datos del Juagdor 1";
        qDebug()<<"ERROR! "<<query2.lastError(); //para mostrar el tipo de error
    }

    //Cargar información del jugador a partir de la tabla player

    if(query2.exec("SELECT * FROM player WHERE id=2 LIMIT 1")){
        while (query2.next()){
            player2->setPx(query2.value(1).toInt());
            player2->setPy(query2.value(2).toInt());
            player2->setVx(query2.value(3).toInt());
            player2->setVy(query2.value(4).toInt());
            player2->setFlagResbalar(query2.value(5).toInt());
            player2->setVUnit(query2.value(6).toInt());
        }
        qDebug()<<"Se ha cargado los datos del Juagdor 2";

    } else {
        qDebug()<<"No se ha cargado los datos del Juagdor 2";
        qDebug()<<"ERROR! "<<query2.lastError(); //para mostrar el tipo de error
    }


    if(query2.exec("SELECT * FROM general WHERE id=1 LIMIT 1")){
        while (query2.next()){
            lcd_s1->display(query2.value(1).toInt());
            lcd_h1->display(query2.value(2).toInt());
        }
        qDebug()<<"Se ha cargado los datos Generales del Jugador 1";

    } else {
        qDebug()<<"No se ha cargado los datos Generales del Jugador 1";
        qDebug()<<"ERROR! "<<query2.lastError(); //para mostrar el tipo de error
    }

    if(query2.exec("SELECT * FROM general WHERE id=2 LIMIT 1")){
        while (query2.next()){
            lcd_s2->display(query2.value(1).toInt());
            lcd_h2->display(query2.value(2).toInt());
        }
        qDebug()<<"Se ha cargado los datos Generales del Jugador 1";

    } else {
        qDebug()<<"No se ha cargado los datos Generales del Jugador 1";
        qDebug()<<"ERROR! "<<query2.lastError(); //para mostrar el tipo de error
    }

}


void optSave::on_pbExit_clicked()
{

    close();
}

void optSave::on_pbSave_clicked()
{
    if(multiplayer){
        insertDatesMultiplayer();
    }
    else{
        insertDates();
    }

    close();
}

Jugador *optSave::getPlayer() const
{
    return player;
}

void optSave::setPlayer(Jugador *value)
{
    player = value;
}

void optSave::on_pbLoad_clicked()
{

    if(multiplayer){
        LoadDatesMultiplayer();
    }
    else{
        LoadDates();
    }
     close();
}

QLCDNumber *optSave::getLcd_h2() const
{
    return lcd_h2;
}

void optSave::setLcd_h2(QLCDNumber *value)
{
    lcd_h2 = value;
}

QLCDNumber *optSave::getLcd_s2() const
{
    return lcd_s2;
}

void optSave::setLcd_s2(QLCDNumber *value)
{
    lcd_s2 = value;
}

QLCDNumber *optSave::getLcd_h1() const
{
    return lcd_h1;
}

void optSave::setLcd_h1(QLCDNumber *value)
{
    lcd_h1 = value;
}

QLCDNumber *optSave::getLcd_s1() const
{
    return lcd_s1;
}

void optSave::setLcd_s1(QLCDNumber *value)
{
    lcd_s1 = value;
}



QList<enemy *> optSave::getEnemies() const
{
    return enemies;
}

void optSave::setEnemies(const QList<enemy *> &value)
{
    enemies = value;
}

bool optSave::getMultiplayer() const
{
    return multiplayer;
}

void optSave::setMultiplayer(bool value)
{
    multiplayer = value;
}

Jugador *optSave::getPlayer2() const
{
    return player2;
}

void optSave::setPlayer2(Jugador *value)
{
    player2 = value;
}
