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
    options_level1=new options(this);
    options_level1->show();
    //level_1=new MainWindow(this);
    //level_1->show();
}

void menu::on_pushButton_2_clicked()
{
    level_2=new level2(this);
    level_2->show();
}

void menu::on_pushButton_3_clicked()
{

}
