#ifndef LEVEL2_H
#define LEVEL2_H

#include <QMainWindow>
#include <level1.h>


namespace Ui {
class level2;
}

class level2 : public MainWindow
{

public:
    explicit level2(QWidget *parent = nullptr);

    ~level2();
public slots:

private:
    Ui::level2 *ui;
};

#endif // LEVEL2_H
