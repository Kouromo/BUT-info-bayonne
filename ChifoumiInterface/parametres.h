#ifndef PARAMETRES_H
#define PARAMETRES_H

#include <QDialog>
#include <QValidator>
#include <QWidget>

namespace Ui {
class parametres;
}

class parametres : public QDialog
{
    Q_OBJECT

public:
    explicit parametres(QWidget *parent = nullptr);
    ~parametres();
public:
    QString getNom();
    int getPointsSaisi();
    int getTempsSaisi();

private:
    Ui::parametres *ui;
};

#endif // PARAMETRES_H
