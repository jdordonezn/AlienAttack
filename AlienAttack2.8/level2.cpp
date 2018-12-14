#include "level2.h"
#include "ui_level2.h"

level2::level2(QWidget *parent) :MainWindow (parent),
    ui(new Ui::level2)
{
    ui->setupUi(this);
    ui->graphicsView2->setScene(this->getScene());
    ui->graphicsView2->setStyleSheet("background: transparent");
    this->setMovie(new QMovie(":/Pictures/fondo4.gif"));
    ui->label2->setMovie(this->getMovie());
    this->getMovie()->start();
    setLcd_score(ui->lcd1);
    ui->lcd->display(getNumHealth());
    setLcd_health(ui->lcd);
    getPlayer()->setFlagResbalar(1);
    getPlayer()->setCd(0);
    getPlayer()->setPx(500);
    setFlagLevel(2);
    setNumAvailableEnemies(35);
    setNumMinScore(25);
}


level2::~level2()
{
    delete ui;
}


