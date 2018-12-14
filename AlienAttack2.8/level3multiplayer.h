#ifndef LEVEL3MULTIPLAYER_H
#define LEVEL3MULTIPLAYER_H

#include <QMainWindow>
#include <level1multiplayer.h>
#include <level3.h>


namespace Ui {
class level3multiplayer;
}
class level3multiplayer : public level3
{
    Q_OBJECT

public:
    explicit level3multiplayer(QWidget *parent = nullptr);
    ~level3multiplayer();
public slots:
    void animar2();

private:
    Ui::level3multiplayer *ui;
    QLCDNumber *lcd_score2;
    QLCDNumber *lcd_health2;
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
    int numHealth2=5;
    int score2=0;

private slots:
    void keyPressEvent(QKeyEvent *ev);



};

#endif // LEVEL3MULTIPLAYER_H
