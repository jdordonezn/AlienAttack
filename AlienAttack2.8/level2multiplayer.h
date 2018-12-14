#ifndef LEVEL2MULTIPLAYER_H
#define LEVEL2MULTIPLAYER_H

#include <QMainWindow>
#include <level1multiplayer.h>

namespace Ui {
class level2multiplayer;
}

class level2multiplayer : public level1Multiplayer
{
    Q_OBJECT

public:
    explicit level2multiplayer(QWidget *parent = nullptr);
    ~level2multiplayer();

private:
    Ui::level2multiplayer *ui;
};

#endif // LEVEL2MULTIPLAYER_H
