#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "level1.h"
#include <QMovie>

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
    MainWindow* level1;
    QMovie *movie;
};

#endif // MENU_H
