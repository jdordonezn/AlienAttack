#include "optionsave.h"
#include "ui_optionsave.h"

optionSave::optionSave(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::optionSave)
{
    ui->setupUi(this);
}

optionSave::~optionSave()
{
    delete ui;
}
