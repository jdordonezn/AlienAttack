#ifndef CARRY_H
#define CARRY_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery> //para realizar consultas
#include <QtSql/QSqlError> //para conocer errores
#include <QDebug>


namespace Ui {
class carry;
}

class carry : public QMainWindow
{
    Q_OBJECT

public:
    explicit carry(QWidget *parent = nullptr);
    void createTables();
    void insertCredential();
    ~carry();

    int getLvl() const;
    void setLvl(int value);

private slots:
    void on_pSave_clicked();

private:
    Ui::carry *ui;
    QSqlDatabase db;
    int lvl;

};

#endif // CARRY_H
