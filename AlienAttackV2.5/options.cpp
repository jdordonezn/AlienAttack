#include "options.h"
#include "ui_options.h"

options::options(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::options)
{
    ui->setupUi(this);
}

options::~options()
{
    delete ui;
}

void options::on_pushButton_clicked(){
    level_1=new MainWindow(this);
    level_1->show();

}

void options::on_pushButton_2_clicked()
{

}
