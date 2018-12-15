#ifndef OPTSAVE_H
#define OPTSAVE_H

#include <QMainWindow>
#include <QMovie>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery> //para realizar consultas
#include <QtSql/QSqlError> //para conocer errores
#include <QLCDNumber>
#include <QDebug>
#include <player.h>
#include <enemy.h>
#include <myscene.h>

namespace Ui {
class optSave;
}

class optSave : public QMainWindow
{
    Q_OBJECT

public:
    explicit optSave(QWidget *parent = nullptr);
    ~optSave();

    void createTables();
    void insertDates();
    void insertDatesMultiplayer();
    void LoadDates();
    void LoadDatesMultiplayer();

    Jugador *getPlayer() const;
    void setPlayer(Jugador *value);

    Jugador *getPlayer2() const;
    void setPlayer2(Jugador *value);

    bool getMultiplayer() const;
    void setMultiplayer(bool value);

    QList<enemy *> getEnemies() const;
    void setEnemies(const QList<enemy *> &value);

    QLCDNumber *getLcd_s1() const;
    void setLcd_s1(QLCDNumber *value);

    QLCDNumber *getLcd_h1() const;
    void setLcd_h1(QLCDNumber *value);

    QLCDNumber *getLcd_s2() const;
    void setLcd_s2(QLCDNumber *value);

    QLCDNumber *getLcd_h2() const;
    void setLcd_h2(QLCDNumber *value);

private slots:
    void on_pbExit_clicked();
    void on_pbSave_clicked();
    void on_pbLoad_clicked();

private:
    Ui::optSave *ui;
    QMovie *movie;
    QSqlDatabase db;
    Jugador* player;
    Jugador* player2;
    enemy* enem;
    QList<enemy*> enemies;
    int numEnemies;
    bool multiplayer=false;
    QLCDNumber *lcd_s1;
    QLCDNumber *lcd_h1;
    QLCDNumber *lcd_s2;
    QLCDNumber *lcd_h2;

    int cont=0;

};

#endif // OPTSAVE_H
