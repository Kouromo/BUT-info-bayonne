#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H
#include "chifoumi.h"
#include <QMainWindow>
#include <cstdlib>

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();
public:
    // ordres reçus par la Présentation
    void miseAJourInterface(Chifoumi::UnCoup, Chifoumi::UnCoup);
    void majScoreJoueur(QString);
    void majScoreMachine(QString);
    void nouvellePartie();
    void txtApropos();

    // La Vue notifie la Présentation - Mise en oeuvre :
    // les signals des éléments de la vue seront connectés à des slots de la Présentation
    void nvelleConnexion(QObject *c);
    void supprConnexion(QObject *c);


private:
    Ui::ChifoumiVue *ui;

};
#endif // CHIFOUMIVUE_H
