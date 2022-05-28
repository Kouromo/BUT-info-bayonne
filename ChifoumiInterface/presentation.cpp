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
    if (LeModele->getScoreJoueur() == laVue->pointMax)
    {
        laVue->messageVictoire('J', tps);
    }
    if (LeModele->getScoreMachine() == laVue->pointMax)
    {
        laVue->messageVictoire('M', tps);
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
    if (LeModele->getScoreJoueur() == laVue->pointMax)
    {
        laVue->messageVictoire('J', tps);
    }
    if (LeModele->getScoreMachine() == laVue->pointMax)
    {
        laVue->messageVictoire('M', tps);
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
    if (LeModele->getScoreJoueur() == laVue->pointMax)
    {
        laVue->messageVictoire('J', tps);
    }
    if (LeModele->getScoreMachine() == laVue->pointMax)
    {
        laVue->messageVictoire('M', tps);
    }
}

void presentation::nouvellePartie()
{
    LeModele->initScores();
    LeModele->initCoups();
    laVue->nouvellePartie();
    tps = laVue->secondesMax; // +1 ?
    bool pause = false;
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
    else // tps = 0 alors
    {
        char gagnant = 'N';
        int scoreGagnant = LeModele->getScoreJoueur();
        if (LeModele->getScoreJoueur() > LeModele->getScoreMachine())
        {
            gagnant = 'J';
            scoreGagnant = LeModele->getScoreJoueur();
        }
        if (LeModele->getScoreMachine() >LeModele->getScoreJoueur())
        {
            gagnant = 'M';
            scoreGagnant = LeModele->getScoreMachine();
        }

        laVue->messageFinTemps(gagnant, scoreGagnant);
    }
}

void presentation::pauseCompteur()
{
    if (pause == false)
    {
        pause = true;
        laVue->arretCompteur();

    }
    else
    {
        pause = false;
        laVue->repriseCompteur();
    }
}


