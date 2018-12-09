#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "level1.h"
#include "level2.h"
#include <QMovie>
#include <options.h>

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
    MainWindow* level_1;
    options* options_level1;
    level2* level_2;
    QMovie *movie;
};

#endif // MENU_H
