#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QMainWindow>
#include <QMovie>
namespace Ui {
class instructions;
}

class instructions : public QMainWindow
{
    Q_OBJECT

public:
    explicit instructions(QWidget *parent = nullptr);
    ~instructions();

private slots:
    void on_pushButton_clicked();

private:
    Ui::instructions *ui;
    QMovie* picture;
};

#endif // INSTRUCTIONS_H
