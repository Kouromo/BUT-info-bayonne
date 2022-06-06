#include "presentation.h"
#include "chifoumivue.h"


presentation::presentation(QObject *parent)
{

}

Chifoumi *presentation::getChifoumi()
{
    return LeModele;
}

ChifoumiVue *presentation::getchifoumiVue()
{
    return laVue;
}

void presentation::setChifoumi(Chifoumi *m)
{
    LeModele=m;
}

void presentation::setVue(ChifoumiVue *v)
{
    laVue=v;
}

void presentation::envoieCiseau()
{
    char gagnant;
    QString Score;
    LeModele->setCoupJoueur(Chifoumi::ciseau);
    LeModele->genererUnCoup();
    laVue->miseAJourInterface(LeModele->getCoupJoueur(), LeModele->getCoupMachine());
    gagnant=LeModele->determinerGagnant();
    LeModele->majScores(gagnant);
    Score.setNum(LeModele->getScoreJoueur());
    laVue->majScoreJoueur(Score);
    Score.setNum(LeModele->getScoreMachine());
    laVue->majScoreMachine(Score);
    if (LeModele->getScoreJoueur() == laVue->pointMax)     // vérif victoire du joueur
    {
        laVue->messageVictoire('J', tps); //envoie à la vue le temps restant
    }
    if (LeModele->getScoreMachine() == laVue->pointMax) // vérif victoire machine
    {
        laVue->messageVictoire('M', tps); //envoie à la vue le temps restant
    }
}

void presentation::envoiePierre()
{
    char gagnant;
    QString Score;
    LeModele->setCoupJoueur(Chifoumi::pierre);
    LeModele->genererUnCoup();
    laVue->miseAJourInterface(LeModele->getCoupJoueur(), LeModele->getCoupMachine());
    gagnant=LeModele->determinerGagnant();
    LeModele->majScores(gagnant);
    Score.setNum(LeModele->getScoreJoueur());
    laVue->majScoreJoueur(Score);
    Score.setNum(LeModele->getScoreMachine());
    laVue->majScoreMachine(Score);
    if (LeModele->getScoreJoueur() == laVue->pointMax) // vérif victoire du joueur
    {
        laVue->messageVictoire('J', tps); //envoie à la vue le temps restant
    }
    if (LeModele->getScoreMachine() == laVue->pointMax) // vérif victoire machine
    {
        laVue->messageVictoire('M', tps); //envoie à la vue le temps restant
    }
}

void presentation::envoiePapier()
{
    char gagnant;
    QString Score;
    LeModele->setCoupJoueur(Chifoumi::papier);
    LeModele->genererUnCoup();
    laVue->miseAJourInterface(LeModele->getCoupJoueur(), LeModele->getCoupMachine());
    gagnant=LeModele->determinerGagnant();
    LeModele->majScores(gagnant);
    Score.setNum(LeModele->getScoreJoueur());
    laVue->majScoreJoueur(Score);
    Score.setNum(LeModele->getScoreMachine());
    laVue->majScoreMachine(Score);
    if (LeModele->getScoreJoueur() == laVue->pointMax) // vérif victoire du joueur
    {
        laVue->messageVictoire('J', tps); //envoie à la vue le temps restant
    }
    if (LeModele->getScoreMachine() == laVue->pointMax) // vérif victoire machine
    {
        laVue->messageVictoire('M', tps); //envoie à la vue le temps restant
    }
}

void presentation::nouvellePartie() // lancement d'une nouvelle partie
{
    LeModele->initScores();
    LeModele->initCoups();
    laVue->nouvellePartie();
    tps = laVue->secondesMax; // à l'exécution défini à tps le nombre de secondes du compte à rebours(+1 ?)
    bool pause = false; // état de jeu en cours au lancement
}

void presentation::aPropos()
{
    laVue->txtApropos();
}

void presentation::compteRebours()
{
    if (tps > 0) // décrémentation du compteur toutes les secondes
    {
        tps--;
        laVue->tempsCompteur(tps);
    }
    else // tps = 0 alors temps écoulé
    {
        char gagnant = 'N'; // Null par défaut
        int scoreGagnant = LeModele->getScoreJoueur(); // Score d'une égalité
        if (LeModele->getScoreJoueur() > LeModele->getScoreMachine()) // scoreJoueur > scoreMachine
        {
            gagnant = 'J';
            scoreGagnant = LeModele->getScoreJoueur();
        }
        if (LeModele->getScoreMachine() >LeModele->getScoreJoueur()) // scoreMachine > scoreJoueur
        {
            gagnant = 'M';
            scoreGagnant = LeModele->getScoreMachine();
        }

        laVue->messageFinTemps(gagnant, scoreGagnant);
    }
}

void presentation::pauseCompteur() // slot bouton compteur
{
    if (pause == false)
    {
        pause = true; // changement de l'état du jeu
        laVue->arretCompteur();

    }
    else
    {
        pause = false; // changement de l'état du jeu
        laVue->repriseCompteur();
    }
}

void presentation::aParametrage()
{
    laVue->parametrage();
}


