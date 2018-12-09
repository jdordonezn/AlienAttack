#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <myscene.h>
#include <player.h>
#include <enemy.h>
#include <QKeyEvent>
#include <bullet.h>
#include <granade.h>
#include <explotion.h>
#include <QMovie>
#include <QLCDNumber>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMovie *getMovie() const;
    void setMovie(QMovie *value);

    myscene *getScene() const;
    void setScene(myscene *value);

    QLCDNumber *getLcd_score() const;
    void setLcd_score(QLCDNumber *value);

    QLCDNumber *getLcd_health() const;
    void setLcd_health(QLCDNumber *value);

    Jugador *getPlayer() const;
    void setPlayer(Jugador *value);

    int getFlagLevel() const;
    void setFlagLevel(int value);

    void SeeMsgScreen();
    void makeAlienLeft();
    void makeAlienRight();

    int getNumMinScore() const;
    void setNumMinScore(int value);

    int getNumAvailableEnemies() const;
    void setNumAvailableEnemies(int value);

public slots:
    void animar();
    void nuevoEnemy();

private:

    Ui::MainWindow *ui;
    QMediaPlayer *soundShot;
    QMediaPlaylist *playList;
    QLCDNumber *lcd_score;
    QLCDNumber *lcd_health;
    QMovie *movie;
    myscene* scene;
    Jugador* player;
    QTimer* timer;
    QTimer* createEnemy;
    QList<enemy*> enemies;
    QGraphicsTextItem *message;
    QList<bullet*> bullets;
    bullet* newBullet;
    QList<granade*> granades;
    granade* newGranade;
    QString _message;
    enemy* newEnemy;
    QList<explotion*> explotions;
    explotion* newExplotion;
    int numHealth=3;
    int score=0;
    int numAvailableGranades=15;
    int numAvailableEnemies=20;
    int numMinScore=15;
    int vUnitShot=1;
    int ajusteRifle=15;
    bool flagJump=false;
    void keyPressEvent(QKeyEvent *ev);
    int flagLevel=1;
};

#endif // MAINWINDOW_H
