#ifndef CONT_H
#define CONT_H

#include <QMainWindow>

namespace Ui {
class cont;
}

class cont : public QMainWindow
{
    Q_OBJECT

public:
    explicit cont(QWidget *parent = nullptr);
    ~cont();

private:
    Ui::cont *ui;
};

#endif // CONT_H
