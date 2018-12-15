#include "exeption.h"
#include "ui_exeption.h"

exeption::exeption(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::exeption)
{
    ui->setupUi(this);
}

exeption::~exeption()
{
    delete ui;
}

void exeption::on_pushButton_clicked()
{
    close();
}
