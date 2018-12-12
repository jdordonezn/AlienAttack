#include "menu.h"
#include "ui_menu.h"


menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    ui->graphicsView->setStyleSheet("background: transparent");
    movie=new QMovie(":/Pictures/original.gif");
    ui->labelMenu->setMovie(movie);
    movie->start();
    optionsLevel=new options(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    optionsLevel->setOp(1);
    optionsLevel->show();
}

void menu::on_pushButton_2_clicked()
{
    optionsLevel->setOp(2);
    optionsLevel->show();
}

void menu::on_pushButton_3_clicked()
{
    optionsLevel->setOp(3);
    optionsLevel->show();
}
