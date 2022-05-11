#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include "chifoumi.h"

#include <cstdlib>
ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);
    connect(ui->bCiseau, SIGNAL(clicked()), this, SLOT(envoieCiseau()));
    connect(ui->bPapier, SIGNAL(clicked()), this, SLOT(envoiePapier()));
    connect(ui->bPierre, SIGNAL(clicked()), this, SLOT(envoiePierre()));
    connect(ui->bNewGame, SIGNAL(clicked()), this, SLOT(nouvellePartie()));
}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

void ChifoumiVue::envoieCiseau()
{
    char gagnant;
    QString Score;
    this->LaPartie.setCoupJoueur(Chifoumi::ciseau);
    LaPartie.genererUnCoup();
    miseAJourInterface(this->LaPartie.getCoupJoueur(), this->LaPartie.getCoupMachine());
    gagnant=LaPartie.determinerGagnant();
    LaPartie.majScores(gagnant);
    Score.setNum(LaPartie.getScoreJoueur());
    ui->lScoreJoueur->setText(Score);
    Score.setNum(LaPartie.getScoreMachine());
    ui->lScoreMachine->setText(Score);
}

void ChifoumiVue::envoiePapier()
{
    char gagnant;
    QString Score;
    this->LaPartie.setCoupJoueur(Chifoumi::papier);
    LaPartie.genererUnCoup();
    miseAJourInterface(this->LaPartie.getCoupJoueur(), this->LaPartie.getCoupMachine());
    gagnant=LaPartie.determinerGagnant();
    LaPartie.majScores(gagnant);
    Score.setNum(LaPartie.getScoreJoueur());
    ui->lScoreJoueur->setText(Score);
    Score.setNum(LaPartie.getScoreMachine());
    ui->lScoreMachine->setText(Score);
}

void ChifoumiVue::envoiePierre()
{
    char gagnant;
    QString Score;
    this->LaPartie.setCoupJoueur(Chifoumi::pierre);
    LaPartie.genererUnCoup();
    miseAJourInterface(this->LaPartie.getCoupJoueur(), this->LaPartie.getCoupMachine());
    gagnant=LaPartie.determinerGagnant();
    LaPartie.majScores(gagnant);
    Score.setNum(LaPartie.getScoreJoueur());
    ui->lScoreJoueur->setText(Score);
    Score.setNum(LaPartie.getScoreMachine());
    ui->lScoreMachine->setText(Score);
}

void ChifoumiVue::miseAJourInterface(Chifoumi::UnCoup coupJoueur, Chifoumi::UnCoup coupMachine)
{
    switch (coupJoueur) {
        case Chifoumi::pierre:
            ui->lFigureJoueur->setPixmap(QPixmap(":/chifoumi/pierre_115.png"));
            break;
        case Chifoumi::ciseau:
            ui->lFigureJoueur->setPixmap(QPixmap(":/chifoumi/ciseau_115.png"));
            break;
        case Chifoumi::papier:
            ui->lFigureJoueur->setPixmap(QPixmap(":/chifoumi/papier_115.png"));
            break;
        default:
            break;
    }

    switch (coupMachine) {
        case Chifoumi::pierre:
            ui->lFigureMachine->setPixmap(QPixmap(":/chifoumi/pierre_115.png"));
            break;
        case Chifoumi::ciseau:
            ui->lFigureMachine->setPixmap(QPixmap(":/chifoumi/ciseau_115.png"));
            break;
        case Chifoumi::papier:
            ui->lFigureMachine->setPixmap(QPixmap(":/chifoumi/papier_115.png"));
            break;
        default:
            break;
    }

}

void ChifoumiVue::nouvellePartie()
{
    ui->lScoreJoueur->setText("0");
    ui->lScoreMachine->setText("0");
    LaPartie.initCoups();
    LaPartie.initScores();
    ui->lFigureJoueur->setPixmap(QPixmap(":/chifoumi/rien_115.png"));
    ui->lFigureMachine->setPixmap(QPixmap(":/chifoumi/rien_115.png"));
}
