#include "level1multiplayer.h"
#include "ui_level1multiplayer.h"

level1Multiplayer::level1Multiplayer(QWidget *parent) :MainWindow(parent),
    ui(new Ui::level1Multiplayer)
{
    ui->setupUi(this);
}

level1Multiplayer::~level1Multiplayer()
{
    delete ui;
}
