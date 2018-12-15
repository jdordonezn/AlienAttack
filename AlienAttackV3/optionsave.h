#ifndef OPTIONSAVE_H
#define OPTIONSAVE_H

#include <QMainWindow>
#include <level1.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery> //para realizar consultas
#include <QtSql/QSqlError> //para conocer errores

namespace Ui {
class optionSave;
}

class optionSave : public QMainWindow
{
    Q_OBJECT

public:
    explicit optionSave(QWidget *parent = nullptr);
    ~optionSave();

private:
    Ui::optionSave *ui;
};

#endif // OPTIONSAVE_H
