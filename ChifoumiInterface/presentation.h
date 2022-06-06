#ifndef PRESENTATION_H
#define PRESENTATION_H
#include <QtDebug>
#include <QObject>
#include "chifoumi.h"
#include "chifoumivue.h"

class presentation : public QObject
{
    Q_OBJECT
public:
    explicit presentation(QObject *parent = nullptr);
private:
    int tps; // Variable du compte à rebours
    bool pause; // Booléen qui ermet de connaître si le jeu est en pause ou nom
public:
    Chifoumi* getChifoumi();
    ChifoumiVue* getchifoumiVue();
    void setChifoumi(Chifoumi *m);
    void setVue(ChifoumiVue *v);
public slots:
    /**
     * @brief les fonctions envoie
     * Elles récupèrent l'information d'un clic sur l'une des 3 figure
     */
    void envoieCiseau();
    void envoiePierre();
    void envoiePapier();
    /**
     * @brief nouvellePartie
     * Permet de passer à l'état de jeu partieEnCours
     */
    void nouvellePartie();
    /**
     * @brief aPropos
     * Appel txtApropos() de la Vue
     */
    void aPropos();
    /**
     * @brief compteRebours
     * Décrémente le nombre de secondes restantes toutes les secondes
     * et appelle la fonction messageFinTemps() quand le temps est écoulé
     */
    void compteRebours();
    /**
     * @brief pauseCompteur
     * change l'état du jeu de pause à jeu en cours
     */
    void pauseCompteur();
    /**
     * @brief aParametrage
     * Appel parametrage() de la Vue
     */
    void aParametrage();
private:
    Chifoumi *LeModele;
    ChifoumiVue *laVue;
};

#endif // PRESENTATION_H
