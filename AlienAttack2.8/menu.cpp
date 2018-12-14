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

    QFontDatabase::addApplicationFont(":/fonts/Pictures/Audiowide.ttf");
    QFont pixel = QFont("Audiowide",60,5);
    ui->label->setFont(pixel);

    //musica de fondo
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/Sound/audio1.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->setVolume(100);
    music->play();
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
