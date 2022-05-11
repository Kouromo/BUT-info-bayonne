/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    Noé Jouve ()
 * Created:   2021-05-10
 * Description : classe m�tier (= mod�le) Chifoumi-v1
 **************************************************************/
#include "chifoumi.h"

#include <cstdlib>
#include <ctime>

 
    ///* ---- PARTIE MOD�LE ---------------------------

Chifoumi::Chifoumi():
coupMachine(rien),
coupJoueur(rien),
scoreJoueur(0),
scoreMachine(0)
{
    //ctor
    // partie mod�le
}

Chifoumi::~Chifoumi()
{
    //dtor
}

        /// Getters

Chifoumi::UnCoup Chifoumi::getCoupJoueur() {
	return (*this).coupJoueur;
}

Chifoumi::UnCoup Chifoumi::getCoupMachine() {
    return (*this).coupMachine;
}

unsigned int Chifoumi::getScoreJoueur() {
    return (*this).scoreJoueur;
}

unsigned int Chifoumi::getScoreMachine() {
    return (*this).scoreMachine;
}

char Chifoumi::determinerGagnant()
{
    char gagnantARetourner;

    // avant de commencer : match nul
    gagnantARetourner = 'N';

    switch (this->coupJoueur)
    {
    case pierre:
        switch (this->coupMachine)
        {
        case pierre:
            
            break;
        case papier:
            gagnantARetourner='M';
            break;
        case ciseau:
            gagnantARetourner='J';
            break;
        }
        break;
    case papier:
        switch (this->coupMachine)
        {
        case pierre:
            gagnantARetourner='J';
            break;
        case papier:
            
            break;
        case ciseau:
            gagnantARetourner='M';
            break;
        }
        break;
    case ciseau:
        switch (this->coupMachine)
        {
        case pierre:
            gagnantARetourner='M';
            break;
        case papier:
            gagnantARetourner='J';
            break;
        case ciseau:
            
            break;
        }
        break;
    default:
        break;
    }


    return gagnantARetourner;
}

         ///* M�thodes utilitaires du Mod�le

int randMinMax(int min, int max){
    /* pr�-condition : min<max ;
       Le nbre al�atoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}

void Chifoumi::genererUnCoup()
{

    unsigned int nbAleatoire;
    nbAleatoire = rand()%(4-1) + 1;
    switch (nbAleatoire)
    {
    case 1 :
         this->coupMachine=Chifoumi::pierre;
        break;
    case 2 :
       this->coupMachine= Chifoumi::papier;
        break;
    case 3 :
        this->coupMachine = Chifoumi::ciseau;
        break;
    default:
        this->coupMachine = Chifoumi::rien;
        break;
    }
}

        /// Setters

void Chifoumi::setCoupJoueur(UnCoup p_coup) {
    (*this).coupJoueur=p_coup;
}

void Chifoumi::setCoupMachine(UnCoup p_coup) {
    (*this).coupMachine=p_coup;
}

void Chifoumi::setScoreJoueur(unsigned int p_score) {
    (*this).scoreJoueur=p_score;
}

void Chifoumi::setScoreMachine(unsigned int p_score) {
    (*this).scoreMachine=p_score;
}

void Chifoumi::majScores(char p_gagnant) {
    switch (p_gagnant)
    {
    case 'N':
        
        break;
    case 'M':
        this->scoreMachine++;
        break;
    case 'J':
        this->scoreJoueur++;
    default:

        break;
    }
}

void Chifoumi::initScores() {
    this->scoreJoueur=0;
    this->scoreMachine=0;
}

void Chifoumi::initCoups() {
    this->coupJoueur=rien;
    this->coupMachine=rien;
}

