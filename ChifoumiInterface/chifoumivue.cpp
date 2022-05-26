#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include "chifoumi.h"
#include <QMessageBox>
#include <cstdlib>
ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);

}
ChifoumiVue::~ChifoumiVue()
{
    delete ui;
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
    QObject::connect(ui->actionA_propos_de, SIGNAL(triggered()), c, SLOT(aPropos()));
}

void ChifoumiVue::supprConnexion(QObject *c)
{
    QObject::disconnect(ui->bCiseau, SIGNAL(clicked()), c, SLOT(envoieCiseau()));
    QObject::disconnect(ui->bPapier, SIGNAL(clicked()), c, SLOT(envoiePapier()));
    QObject::disconnect(ui->bPierre, SIGNAL(clicked()), c, SLOT(envoiePierre()));
    QObject::disconnect(ui->bNewGame, SIGNAL(clicked()), c, SLOT(nouvellePartie()));
    QObject::disconnect(ui->actionA_propos_de, SIGNAL(triggered()), c, SLOT(aPropos()));
}


void ChifoumiVue::nouvellePartie()
{
    ui->lScoreJoueur->setText("0");
    ui->lScoreMachine->setText("0");
    ui->lFigureJoueur->setPixmap(QPixmap(":/chifoumi/rien_115.png"));
    ui->lFigureMachine->setPixmap(QPixmap(":/chifoumi/rien_115.png"));
    ui->bCiseau->setEnabled(true);
    ui->bPapier->setEnabled(true);
    ui->bPierre->setEnabled(true);

}

void ChifoumiVue::txtApropos()
{
    QMessageBox msg;
    msg.setWindowTitle("A propos de cette application");
    msg.setText("Jeu du Chifoumi v3 \r\n"" Créé le  04/04/2022 par ALVES Matéo et JOUVE Noé TD2 - TP4 ");
    msg.exec();
}

