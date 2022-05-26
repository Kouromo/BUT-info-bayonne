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
}

void presentation::nouvellePartie()
{
    LeModele->initScores();
    LeModele->initCoups();
    laVue->nouvellePartie();
}

void presentation::aPropos()
{
    laVue->txtApropos();
}
