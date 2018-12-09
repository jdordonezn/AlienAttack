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

private:
    Ui::level1Multiplayer *ui;
};

#endif // LEVEL1MULTIPLAYER_H
