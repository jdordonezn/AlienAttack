#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <level2.h>
#include <level2multiplayer.h>
#include <level3.h>
#include <level3multiplayer.h>
#include <exeption.h>

namespace Ui {
class login;
}

class login : public carry
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    void consultar();
    ~login();

    int getLvlReal() const;
    void setLvlReal(int value);

    bool getMultiplayer() const;
    void setMultiplayer(bool value);

private slots:
    void on_pSend_clicked();

private:
    Ui::login *ui;
    int lvlReal;
    bool multiplayer=false;
    level2* lv2;
    level3* lv3;
    level2multiplayer* lv2M;
    level3multiplayer* lv3M;
    bool userValido;
    exeption* exp;
};

#endif // LOGIN_H
