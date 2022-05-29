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
    // VARIABLES PUBLIQUES
    unsigned short int pointMax = 5; // Nombre de points pour gagner (5 points par défaut)
    unsigned short int secondesMax = 30; //Temps du timer en mili-secondes (30 secondes par défaut)

    // ordres reçus par la Présentation
    /**
     * @brief miseAJourInterface
     * Change les images dans les vignettes représentant le joueur et la machine
     */
    void miseAJourInterface(Chifoumi::UnCoup, Chifoumi::UnCoup);
    /**
     * @brief les majScore mettent à joueur le score montré sur l'interface utilisateur
     */
    void majScoreJoueur(QString);
    void majScoreMachine(QString);
    void nouvellePartie();
    void txtApropos(); // Message Box de texte pour afficher les informations de l'application
    // La Vue notifie la Présentation - Mise en oeuvre :
    // les signals des éléments de la vue seront connectés à des slots de la Présentation
    void nvelleConnexion(QObject *c);
    void supprConnexion(QObject *c);
    /**
     * @brief messageVictoire
     * Permet de passer à l'état finPartie lorsque le score atteint celui de la variable pointMax
     */
    void messageVictoire(char, unsigned short int);
    /**
     * @brief messageFinTemps
     * Permet de passer à l'état finPartie lorsque le temps est écoulé
     */
    void messageFinTemps(char, unsigned short int);
    void tempsCompteur(unsigned int); // Mise à jour du temps affiché
    void arretCompteur(); // Arrête le timer et passe à l'état partieEnPause
    void repriseCompteur(); // Reprend le jeu et repasse à l'état partieEnCours

private:
    Ui::ChifoumiVue *ui;
    QTimer *chrono = new QTimer(this);
};
#endif // CHIFOUMIVUE_H
