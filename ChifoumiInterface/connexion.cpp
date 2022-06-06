#include "connexion.h"
#include "ui_connexion.h"

connexion::connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connexion)
{
    ui->setupUi(this);

}

connexion::~connexion()
{
    delete ui;
}

bool connexion::verifConnexion()
{
    maDb= new database;
    bool okbd= maDb->openDatabase();
    bool okReq= false;
    // on teste si on est bien connecté
    if (!okbd)
    {
        return false;
    }

    QSqlQuery maRequete("select nomJoueur, motDePasse from joueur"); // on écrit la requête
   for (int i=0; maRequete.next(); i++)
   {


       if (maRequete.value(0).toString() == getNom() && maRequete.value(1) == getMdp())
       {
           okReq=true;
           break;
       }
    }



    if (okReq)
    {
        return true;
    }

    return false;
}

QString connexion::getNom()
{
    return ui->lIdenifiant->text();
}

QString connexion::getMdp()
{
    return ui->lMdp->text();
}
