#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myscene.h>
#include <jugador.h>
#include <bala.h>
#include <granada.h>
#include <enemy.h>
#include <QKeyEvent>
#include <QTimer>
#include <QMovie>
#include <QMediaPlayer>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QMovie *movie;
    QMediaPlayer *gunSound;

    Jugador* jugador;
    QTimer* timer;
    QTimer* crearEnemy;
    bool flagJump=false;
    void keyPressEvent(QKeyEvent *ev);
    QList<bala*> balas;
    QList<granada*> granadas;
    QList<enemy*> enemies;
    bala* newBala;
    granada* newGranada;
    enemy* newEnemy;
    int numHealth=5;
    int score=0;



};
#endif // MAINWINDOW_H
