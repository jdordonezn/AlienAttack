#ifndef OPTIONS_H
#define OPTIONS_H

#include <QMainWindow>
#include <QMovie>
#include <level1.h>
#include <level1multiplayer.h>
//#include <level2.h>
//#include <level2multiplayer.h>
#include <level3.h>
#include <level3multiplayer.h>
#include <QFontDatabase>
#include <QFont>
#include <login.h>

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
    login* log;
    int op;
};

#endif // OPTIONS_H
