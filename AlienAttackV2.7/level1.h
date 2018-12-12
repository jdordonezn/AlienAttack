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
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>

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
    void makeAlienUp();

    int getNumMinScore() const;
    void setNumMinScore(int value);

    int getNumAvailableEnemies() const;
    void setNumAvailableEnemies(int value);

    int getAjusteRifle() const;
    void setAjusteRifle(int value);

    int getVUnitShot() const;
    void setVUnitShot(int value);

    bool getFlagJump() const;
    void setFlagJump(bool value);

    bullet *getNewBullet() const;
    void setNewBullet(bullet *value);

    QList<bullet *> getBullets() const;
    void setBullets(const QList<bullet *> &value);

    granade *getNewGranade() const;
    void setNewGranade(granade *value);

    QList<granade *> getGranades() const;
    void setGranades(const QList<granade *> &value);

    QTimer *getTimer() const;
    void setTimer(QTimer *value);

    QList<explotion *> getExplotions() const;
    void setExplotions(const QList<explotion *> &value);

    QList<enemy *> getEnemies() const;
    void setEnemies(const QList<enemy *> &value);

    QString getMessage() const;
    void setMessage(const QString &message);

    int getNumHealth() const;
    void setNumHealth(int value);

    bool getMultijugador() const;
    void setMultijugador(bool value);

    int getScore() const;
    void setScore(int value);

public slots:
    void animar();
    void nuevoEnemy();
    void save();

private:

    Ui::MainWindow *ui;
    /*
    QMediaPlayer *soundShot;
    QMediaPlaylist *playList;
    */
    QTextEdit*  textEdit;

    QLCDNumber *lcd_score;
    QString msg="Prueba";
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
    int flagLevel=1;
    bool multijugador=false;

private slots:
    void keyPressEvent(QKeyEvent *ev);
};

#endif // MAINWINDOW_H
