#ifndef LEVEL3_H
#define LEVEL3_H

#include <QMainWindow>
#include <level1.h>

namespace Ui {
class level3;
}

class level3 : public MainWindow
{
    Q_OBJECT

public:
    explicit level3(QWidget *parent = nullptr);
    ~level3();


    QList<enemy *> getEnemiesThrow() const;
    void setEnemiesThrow(const QList<enemy *> &value);

public slots:
    void newThrowEnemy();
    void animarThrow();

private:
    Ui::level3 *ui;
    QTimer* timerThrowE;
    QList<enemy*> enemiesThrow;
    enemy* newEnemyThrow;
    explotion* newExplotionAux;
    QList<explotion*> eplotionsAux;
};

#endif // LEVEL3_H
