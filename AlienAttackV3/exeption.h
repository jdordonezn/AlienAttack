#ifndef EXEPTION_H
#define EXEPTION_H

#include <QMainWindow>

namespace Ui {
class exeption;
}

class exeption : public QMainWindow
{
    Q_OBJECT

public:
    explicit exeption(QWidget *parent = nullptr);
    ~exeption();

private slots:
    void on_pushButton_clicked();

private:
    Ui::exeption *ui;
};

#endif // EXEPTION_H
