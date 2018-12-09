#ifndef OPTIONS_H
#define OPTIONS_H

#include <QMainWindow>
#include <level1.h>

namespace Ui {
class options;
}

class options : public QMainWindow
{
    Q_OBJECT

public:
    explicit options(QWidget *parent = nullptr);
    ~options();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::options *ui;
    MainWindow* level_1;
};

#endif // OPTIONS_H
