#ifndef CONTINUE_H
#define CONTINUE_H

#include <QMainWindow>

namespace Ui {
class continue;
}

class continue : public QMainWindow
{
    Q_OBJECT

public:
    explicit continue(QWidget *parent = nullptr);
    ~continue();

private:
    Ui::continue *ui;
};

#endif // CONTINUE_H
