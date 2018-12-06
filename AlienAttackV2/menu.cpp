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
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    level1=new MainWindow(this);
    level1->show();
}

void menu::on_pushButton_2_clicked()
{

}

void menu::on_pushButton_3_clicked()
{

}
