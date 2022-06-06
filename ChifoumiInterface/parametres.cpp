#include "parametres.h"
#include "ui_parametres.h"

parametres::parametres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parametres)
{
    ui->setupUi(this);

    QRegExp carAutorises("[0-9]{1,}"); // Autoriser uniquement des nombres
    QRegExpValidator *validateur = new QRegExpValidator(carAutorises, this);
    ui->eSecondes->setValidator(validateur);
    ui->ePoints->setValidator(validateur);
    setWindowTitle("Paramétrage");
}

parametres::~parametres()
{
    delete ui;
}

QString parametres::getNom()
{
    return ui->eNom->text();
}

int parametres::getPointsSaisi()
{
    return ui->ePoints->text().toInt();
}

int parametres::getTempsSaisi()
{
    return ui->eSecondes->text().toInt();
}
