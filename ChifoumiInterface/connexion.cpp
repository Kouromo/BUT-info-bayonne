#include "connexion.h"
#include "ui_connexion.h"

connexion::connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connexion)
{
    ui->setupUi(this);
    QObject::connect(ui->bConfirm, SIGNAL(clicked()), this, SLOT(confirmerConnec()));
    setWindowTitle("Connexion");
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
    // on parcours tout les nomJoueur et mdp
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



bool connexion::getEtat()
{
    return this->etatConnec;
}

QString connexion::getNom()
{
    return ui->eIdenifiant->text();
}

QString connexion::getMdp()
{
    return ui->eMdp->text();
}

void connexion::confirmerConnec()
{
    if (!verifConnexion())
    {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Information);
        msg.setWindowTitle("Échec de la connexion");
        msg.setText("Une erreur a été rencontrée");
        msg.exec();
    }
    else
    {
        this->etatConnec=true;
        this->close();
    }
}
