#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include "chifoumi.h"

#include <cstdlib>
ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);
<<<<<<< HEAD
=======
    connect(ui->bCiseau, SIGNAL(clicked()), this, SLOT(envoieCiseau()));
    connect(ui->bPapier, SIGNAL(clicked()), this, SLOT(envoiePapier()));
    connect(ui->bPierre, SIGNAL(clicked()), this, SLOT(envoiePierre()));
    connect(ui->bNewGame, SIGNAL(clicked()), this, SLOT(nouvellePartie()));
}
>>>>>>> fabf1119779f2764e9e77a199198cea1f8b3a1f7

}
ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

<<<<<<< HEAD

=======
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
>>>>>>> fabf1119779f2764e9e77a199198cea1f8b3a1f7

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

<<<<<<< HEAD
void ChifoumiVue::majScoreJoueur(QString score)
{
    ui->lScoreJoueur->setText(score);
}

void ChifoumiVue::majScoreMachine(QString score)
{
    ui->lScoreMachine->setText(score);
}

void ChifoumiVue::nvelleConnexion(QObject *c)
{
    QObject::connect(ui->bCiseau, SIGNAL(clicked()), c, SLOT(envoieCiseau()));
    QObject::connect(ui->bPapier, SIGNAL(clicked()), c, SLOT(envoiePapier()));
    QObject::connect(ui->bPierre, SIGNAL(clicked()), c, SLOT(envoiePierre()));
    QObject::connect(ui->bNewGame, SIGNAL(clicked()), c, SLOT(nouvellePartie()));
}

void ChifoumiVue::supprConnexion(QObject *c)
{
    QObject::disconnect(ui->bCiseau, SIGNAL(clicked()), c, SLOT(envoieCiseau()));
    QObject::disconnect(ui->bPapier, SIGNAL(clicked()), c, SLOT(envoiePapier()));
    QObject::disconnect(ui->bPierre, SIGNAL(clicked()), c, SLOT(envoiePierre()));
    QObject::disconnect(ui->bNewGame, SIGNAL(clicked()), c, SLOT(nouvellePartie()));
}


void ChifoumiVue::nvllepartie()
{
    ui->lScoreJoueur->setText("0");
    ui->lScoreMachine->setText("0");
    ui->lFigureJoueur->setPixmap(QPixmap(":/chifoumi/rien_115.png"));
    ui->lFigureMachine->setPixmap(QPixmap(":/chifoumi/rien_115.png"));
}

=======
void ChifoumiVue::nouvellePartie()
{
    ui->lScoreJoueur->setText("0");
    ui->lScoreMachine->setText("0");
    LaPartie.initCoups();
    LaPartie.initScores();
    ui->lFigureJoueur->setPixmap(QPixmap(":/chifoumi/rien_115.png"));
    ui->lFigureMachine->setPixmap(QPixmap(":/chifoumi/rien_115.png"));
}
>>>>>>> fabf1119779f2764e9e77a199198cea1f8b3a1f7
