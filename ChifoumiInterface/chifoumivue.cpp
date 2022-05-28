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

    QString pointVictoire;
    pointVictoire.setNum(pointMax);
    ui->lPointGagnant->setText(pointVictoire);
    QString tempsRestant;
    tempsRestant.setNum(secondesMax);
    ui->lSecondes->setText(tempsRestant);

    //couleurs
    ui->lScoreJoueur->setStyleSheet("QLabel {color : blue;}");
    ui->lJoueur->setStyleSheet("QLabel {color : blue;}");
    ui->lMachine->setStyleSheet("QLabel {color : black;}");
    ui->lScoreMachine->setStyleSheet("QLabel {color : black;}");
    ui->lPointGagnant->setStyleSheet("QLabel {color : grey;}");
    ui->lGagne->setStyleSheet("QLabel {color : grey;}");
    ui->lTemps->setStyleSheet("QLabel {color : grey;}");
    ui->lSecondes->setStyleSheet("QLabel {color : grey;}");

    chrono->setInterval(1000);
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
    QObject::connect(chrono, SIGNAL(timeout()), c, SLOT(compteRebours()));
}

void ChifoumiVue::supprConnexion(QObject *c)
{
    QObject::disconnect(ui->bCiseau, SIGNAL(clicked()), c, SLOT(envoieCiseau()));
    QObject::disconnect(ui->bPapier, SIGNAL(clicked()), c, SLOT(envoiePapier()));
    QObject::disconnect(ui->bPierre, SIGNAL(clicked()), c, SLOT(envoiePierre()));
    QObject::disconnect(ui->bNewGame, SIGNAL(clicked()), c, SLOT(nouvellePartie()));
    QObject::disconnect(ui->actionA_propos_de, SIGNAL(triggered()), c, SLOT(aPropos()));
    QObject::disconnect(chrono, SIGNAL(timeout()), c, SLOT(compteRebours()));
}

void ChifoumiVue::messageVictoire(char personne, unsigned short int temps)
{
    ui->bCiseau->setEnabled(false);
    ui->bPapier->setEnabled(false);
    ui->bPierre->setEnabled(false);
    chrono->stop();
    unsigned short int tpsRestant = secondesMax - temps;

    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    msg.setWindowTitle("Fin de partie gagnant");
    if (personne == 'M')
    {
        QString message = QString("Bravo La Machine ! Vous gagnez avec %1 points en %2 secondes.").arg(pointMax).arg(tpsRestant);
        msg.setText(message);
    }
    else
    {
        QString message = QString("Bravo Vous ! Vous gagnez avec %1 points en %2 secondes.").arg(pointMax).arg(tpsRestant);
        msg.setText(message);
    }
    msg.exec();

}

void ChifoumiVue::messageFinTemps(char resultat, unsigned short int score)
{
    ui->bCiseau->setEnabled(false);
    ui->bPapier->setEnabled(false);
    ui->bPierre->setEnabled(false);
    chrono->stop();
    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    QString personne;
    if (resultat == 'J')
        personne = "Vous terminez";
    if (resultat == 'M')
        personne = "La machine termine";
    
    if (resultat == 'N') //  ex aequo
    {
        msg.setWindowTitle("Fin de partie temps : pas d'avantage");
        QString message = QString("Hélas chers joueurs, temps de jeu fini ! Le jeu se termine sur une égalité avec tous deux %1 points.").arg(score);
        msg.setText(message);
        msg.exec();
    }
    else
    {
        msg.setIcon(QMessageBox::Information);
        msg.setWindowTitle("Fin de partie temps : 1 avantage");
        QString message = QString("Hélas chers joueurs, temps de jeu fini ! %1 toutefois mieux, avec %2 points.").arg(personne).arg(score);
        msg.setText(message);
        msg.exec();
    }

}

void ChifoumiVue::tempsCompteur(unsigned int temps)
{
    QString tempsRestant;
    tempsRestant.setNum(temps);
    ui->lSecondes->setText(tempsRestant);
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
    chrono->start(); // convertion en mili-secondes

}

void ChifoumiVue::txtApropos() // raccourci F1
{
    QMessageBox msg;
    msg.setWindowTitle("A propos de cette application");
    msg.setText("Jeu du Chifoumi v5 \r\n"" Créé le  04/04/2022 par ALVES Matéo et JOUVE Noé TD2 - TP4 ");
    msg.exec();
}

