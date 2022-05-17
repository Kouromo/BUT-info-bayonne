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
<<<<<<< HEAD
public:
    // ordres reçus par la Présentation
    void miseAJourInterface(Chifoumi::UnCoup, Chifoumi::UnCoup);
    void majScoreJoueur(QString);
    void majScoreMachine(QString);
    void nvllepartie();

    // La Vue notifie la Présentation - Mise en oeuvre :
    // les signals des éléments de la vue seront connectés à des slots de la Présentation
    void nvelleConnexion(QObject *c);
    void supprConnexion(QObject *c);
=======
public slots:
    void envoieCiseau();
    void envoiePierre();
    void envoiePapier();
    void nouvellePartie();

public:
    void miseAJourInterface(Chifoumi::UnCoup, Chifoumi::UnCoup);
>>>>>>> fabf1119779f2764e9e77a199198cea1f8b3a1f7


private:
    Ui::ChifoumiVue *ui;
<<<<<<< HEAD

=======
    Chifoumi LaPartie;
>>>>>>> fabf1119779f2764e9e77a199198cea1f8b3a1f7
};
#endif // CHIFOUMIVUE_H
