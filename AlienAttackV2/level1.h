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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void animar();
     void nuevoEnemy();
     void SeeMsgScreen();
private:
    Ui::MainWindow *ui;
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
    int numHealth=5;
    int score=0;
    int numAvailableGranades=15;
    int numAvailableEnemies=20;
    int numMinScore=15;
    int vUnitShot=1;
    int ajusteRifle=15;
    bool flagJump=false;
    void keyPressEvent(QKeyEvent *ev);

};

#endif // MAINWINDOW_H
