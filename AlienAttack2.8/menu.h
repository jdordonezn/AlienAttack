#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QMovie>
#include <options.h>
#include <QFont>
#include <QFontDatabase>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);

    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::menu *ui;
    options* optionsLevel;
    QMovie *movie;
    QMediaPlayer * music;
    QMediaPlaylist *playlist;
};

#endif // MENU_H
