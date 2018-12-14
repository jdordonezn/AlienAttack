#ifndef OPTIONS_H
#define OPTIONS_H

#include <QMainWindow>
#include <QMovie>
#include <level1.h>
#include <level1multiplayer.h>
#include <level2.h>
#include <level2multiplayer.h>
#include <level3.h>
#include <level3multiplayer.h>
#include <QFont>
#include <QFontDatabase>


namespace Ui {
class options;
}

class options : public QMainWindow
{
    Q_OBJECT

public:
    explicit options(QWidget *parent = nullptr);
    ~options();

    int getOp() const;
    void setOp(int value);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::options *ui;
    QMovie *movie;
    MainWindow* level_1;
    level1Multiplayer* level_1M;
    level2* level_2;
    level2multiplayer* level_2M;
    level3* level_3;
    level3multiplayer* level_3M;
    int op;
};

#endif // OPTIONS_H
