#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H
#include "chifoumi.h"
#include <QMainWindow>
#include <cstdlib>
#include <QTimer>

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
    unsigned short int pointMax = 5; // Nombre de points pour gagner (5 points par défaut)
    unsigned short int secondesMax = 30; //Temps du timer en mili-secondes (30 secondes par défaut)
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
    void messageVictoire(char, unsigned short int);
    void messageFinTemps(char, unsigned short int);
    void tempsCompteur(unsigned int);

private:
    Ui::ChifoumiVue *ui;
    QTimer *chrono = new QTimer(this);
};
#endif // CHIFOUMIVUE_H
