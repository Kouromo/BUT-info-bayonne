#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include "chifoumi.h"
#include <QMessageBox>
#include <cstdlib>

ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , nom("Vous")
    , pointMax(5)
    , secondesMax(30)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);

    //couleurs
    ui->lScoreJoueur->setStyleSheet("QLabel {color : blue;}");
    ui->lJoueur->setStyleSheet("QLabel {color : blue;}");
    ui->lMachine->setStyleSheet("QLabel {color : black;}");
    ui->lScoreMachine->setStyleSheet("QLabel {color : black;}");
    ui->lPointGagnant->setStyleSheet("QLabel {color : grey;}");
    ui->lGagne->setStyleSheet("QLabel {color : grey;}");
    ui->lTemps->setStyleSheet("QLabel {color : grey;}");
    ui->lSecondes->setStyleSheet("QLabel {color : grey;}");

    affichagePointsTemps(pointMax, secondesMax);

    chrono->setInterval(1000); // pulsation toutes les secondes



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
    QObject::connect(ui->bPause, SIGNAL(clicked()), c, SLOT(pauseCompteur()));
    QObject::connect(ui->actionParam_trer, SIGNAL(triggered()), c, SLOT(aParametrage()));
}

void ChifoumiVue::supprConnexion(QObject *c)
{
    QObject::disconnect(ui->bCiseau, SIGNAL(clicked()), c, SLOT(envoieCiseau()));
    QObject::disconnect(ui->bPapier, SIGNAL(clicked()), c, SLOT(envoiePapier()));
    QObject::disconnect(ui->bPierre, SIGNAL(clicked()), c, SLOT(envoiePierre()));
    QObject::disconnect(ui->bNewGame, SIGNAL(clicked()), c, SLOT(nouvellePartie()));
    QObject::disconnect(ui->actionA_propos_de, SIGNAL(triggered()), c, SLOT(aPropos()));
    QObject::disconnect(chrono, SIGNAL(timeout()), c, SLOT(compteRebours()));
    QObject::disconnect(ui->bPause, SIGNAL(clicked()), c, SLOT(pauseCompteur()));
    QObject::disconnect(ui->actionParam_trer, SIGNAL(triggered()), c, SLOT(aParametrage()));
}

void ChifoumiVue::messageVictoire(char personne, unsigned short int temps) // Victoire atteinte du pointMax défini
{
    // désactivation des boutons de jeu
    ui->bCiseau->setEnabled(false);
    ui->bPapier->setEnabled(false);
    ui->bPierre->setEnabled(false);
    ui->bPause->setEnabled(false);
    chrono->stop(); // arrêt du chrono
    unsigned short int tpsRestant = secondesMax - temps; // calcul du temps de jeu

    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    msg.setWindowTitle("Fin de partie gagnant");
    if (personne == 'M') // Victoire Machine
    {
        QString message = QString("Bravo La Machine ! Vous gagnez avec %1 points en %2 secondes.").arg(pointMax).arg(tpsRestant);
        msg.setText(message);
    }
    else // Victoire Joueur
    {
        QString message = QString("Bravo Vous ! Vous gagnez avec %1 points en %2 secondes.").arg(pointMax).arg(tpsRestant);
        msg.setText(message);
    }
    msg.exec();
    ui->actionParam_trer->setEnabled(true); // réactivation du paramétrage
}

void ChifoumiVue::messageFinTemps(char resultat, unsigned short int score) // Temps écoulé défini par secondesMax
{
    // désactivation des boutons de jeu
    ui->bCiseau->setEnabled(false);
    ui->bPapier->setEnabled(false);
    ui->bPierre->setEnabled(false);
    ui->bPause->setEnabled(false);
    chrono->stop(); // arrêt du chrono

    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    QString personne;
    if (resultat == 'J') // Victoire Joueur
        personne = ("Vous terminez");
    if (resultat == 'M') // Victoire Machine
        personne = "La machine termine";
    
    if (resultat == 'N') //  ex aequo
    {
        msg.setWindowTitle("Fin de partie temps : pas d'avantage");
        QString message = QString("Hélas chers joueurs, temps de jeu fini ! Le jeu se termine sur une égalité avec tous deux %1 points.").arg(score);
        msg.setText(message);
    }
    else // Victoire d'un des joueurs (même message)
    {
        msg.setIcon(QMessageBox::Information);
        msg.setWindowTitle("Fin de partie temps : 1 avantage");
        QString message = QString("Hélas chers joueurs, temps de jeu fini ! %1 toutefois mieux, avec %2 points.").arg(personne).arg(score);
        msg.setText(message);
    }
    msg.exec();
    ui->actionParam_trer->setEnabled(true); // réactivation du paramétrage
}

void ChifoumiVue::tempsCompteur(unsigned int temps) // afiche le temps restant du compteur sur la vue
{                                                   // en prennant pour paramètre le temps restant en secondes
    QString tempsRestant;
    tempsRestant.setNum(temps);
    ui->lSecondes->setText(tempsRestant);
}

void ChifoumiVue::arretCompteur() // arrête le compte à rebours et désactive les boutons de jeu
{
    chrono->stop();
    ui->bPause->setText("Reprise jeu");
    ui->bCiseau->setEnabled(false);
    ui->bPapier->setEnabled(false);
    ui->bPierre->setEnabled(false);
    ui->bNewGame->setEnabled(false);
}

void ChifoumiVue::repriseCompteur() // reprend le compte à rebours et réactive les boutons de jeu
{
    chrono->start();
    ui->bPause->setText("Pause");
    ui->bCiseau->setEnabled(true);
    ui->bPapier->setEnabled(true);
    ui->bPierre->setEnabled(true);
    ui->bNewGame->setEnabled(true);
}

void ChifoumiVue::parametrage()
{
    parametres * dlgParam = new parametres(this);
    if (dlgParam->exec() == QDialog::Accepted) // si clique sur ok
    {
        pointMax = dlgParam->getPointsSaisi(); // Application des paramètres
        secondesMax = dlgParam->getTempsSaisi();
        nom = dlgParam->getNom();
        affichagePointsTemps(pointMax, secondesMax);
        ui->lJoueur->setText(nom);
    }
}

void ChifoumiVue::affichagePointsTemps(int maximumPoints, int maximumSecondes)
{
    QString pointVictoire;
    pointVictoire.setNum(maximumPoints);
    ui->lPointGagnant->setText(pointVictoire);
    QString tempsRestant;
    tempsRestant.setNum(maximumSecondes);
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
    ui->bPause->setEnabled(true);
    ui->actionParam_trer->setEnabled(false);
    chrono->start(); // convertion en mili-secondes
}

void ChifoumiVue::txtApropos() // raccourci F1
{
    QMessageBox msg;
    msg.setWindowTitle("A propos de cette application");
    msg.setText("Jeu du Chifoumi v6 \r\n"" Créé le  04/04/2022 par ALVES Matéo et JOUVE Noé TD2 - TP4 ");
    msg.exec();
}

