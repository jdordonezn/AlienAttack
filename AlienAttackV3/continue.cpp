#include "continue.h"
#include "ui_continue.h"

continue::continue(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::continue)
{
    ui->setupUi(this);
}

continue::~continue()
{
delete ui;
}
