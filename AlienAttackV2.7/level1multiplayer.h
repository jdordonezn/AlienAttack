#ifndef LEVEL1MULTIPLAYER_H
#define LEVEL1MULTIPLAYER_H

#include <QMainWindow>
#include <level1.h>

namespace Ui {
class level1Multiplayer;
}

class level1Multiplayer : public MainWindow
{
    Q_OBJECT

public:
    explicit level1Multiplayer(QWidget *parent = nullptr);
    ~level1Multiplayer();
    Jugador *getPlayer2() const;
    void setPlayer2(Jugador *value);


    QLCDNumber *getLcd_score2() const;
    void setLcd_score2(QLCDNumber *value);

    QLCDNumber *getLcd_health2() const;
    void setLcd_health2(QLCDNumber *value);

    int getNumHealth2() const;
    void setNumHealth2(int value);

    QList<bullet *> getBullets2() const;
    void setBullets2(const QList<bullet *> &value);

    int getScore2() const;
    void setScore2(int value);

    QList<granade *> getGranades2() const;
    void setGranades2(const QList<granade *> &value);

public slots:
    void animar2();

private:
    QLCDNumber *lcd_score2;
    QLCDNumber *lcd_health2;
    Ui::level1Multiplayer *ui;
    Jugador* player2;
    QList<bullet*> bullets2;
    QList<bullet*> bulletsAux;
    bullet* newBullet2;
    QList<granade*> granades2;
    QList<granade*> granadesAux;
    granade* newGranade2;
    QList<explotion*> explotions2;
    explotion* newExplotion2;
    int ajusteRifle2=15;
    int numAvailableGranades2=15;
    bool flagJump2=false;
    int vUnitShot2=1;
    int numHealth2=3;
    int score2=0;


private slots:
    void keyPressEvent(QKeyEvent *ev);
};

#endif // LEVEL1MULTIPLAYER_H
