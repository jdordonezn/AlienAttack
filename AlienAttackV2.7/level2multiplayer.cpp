#include "level2multiplayer.h"
#include "ui_level2multiplayer.h"

level2multiplayer::level2multiplayer(QWidget *parent) :
    level1Multiplayer (parent),
    ui(new Ui::level2multiplayer)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(this->getScene());
    ui->graphicsView->setStyleSheet("background: transparent");
    this->setMovie(new QMovie(":/Pictures/fondo4.gif"));
    ui->label->setMovie(this->getMovie());
    this->getMovie()->start();
    setLcd_score(ui->lcd_sc1);
    setLcd_health(ui->lcd_hl1);
    ui->lcd_hl1->display(getNumHealth());
    setLcd_score2(ui->lcd_sc2);
    setLcd_health2(ui->lcd_hl2);
    ui->lcd_hl2->display(getNumHealth2());
    setFlagLevel(2);
    getPlayer()->setFlagResbalar(1);
    getPlayer()->setCd(0);
    getPlayer()->setPx(500);
    getPlayer2()->setFlagResbalar(1);
    getPlayer2()->setCd(0);
    getPlayer2()->setPx(400);
    setNumAvailableEnemies(35);
    setNumMinScore(25);

}

level2multiplayer::~level2multiplayer()
{
    delete ui;
}
