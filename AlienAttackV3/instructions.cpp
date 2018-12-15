#include "instructions.h"
#include "ui_instructions.h"

instructions::instructions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::instructions)
{
    ui->setupUi(this);
    ui->graphicsView->setStyleSheet("background: transparent");
    picture=new QMovie(":/Pictures/instrucciones.png");
    ui->im1->setMovie(picture);
    picture->start();
}

instructions::~instructions()
{
    delete ui;
}

void instructions::on_pushButton_clicked()
{
    close();
}
