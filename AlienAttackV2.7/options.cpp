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

    switch (op) {
        case(1):
            level_1=new MainWindow();
            level_1->show();
            break;
        case(2):
            level_2=new level2();
            level_2->show();
            break;
        case (3):
            level_3=new level3();
            level_3->show();
            break;
    };
}

void options::on_pushButton_2_clicked(){

    switch (op) {
        case(1):
            level_1M=new level1Multiplayer();
            level_1M->show();
            break;
        case(2):
            level_2M=new level2multiplayer();
            level_2M->show();
            break;
        case(3):
            level_3M=new level3multiplayer();
            level_3M->show();
            break;
    };

}

int options::getOp() const
{
    return op;
}

void options::setOp(int value)
{
    op = value;
}
