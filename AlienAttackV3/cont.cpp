#include "cont.h"
#include "ui_cont.h"

cont::cont(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cont)
{
    ui->setupUi(this);
}

cont::~cont()
{
    delete ui;
}
