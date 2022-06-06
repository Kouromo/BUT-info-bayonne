#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>
#include "database.h"
#include <QMessageBox>
namespace Ui {
class connexion;
}

class connexion : public QDialog
{
    Q_OBJECT

public:
    explicit connexion(QWidget *parent = nullptr);
    ~connexion();
private:
      bool verifConnexion(); // fonction qui va vérfier  si on est bien connecté.

public:
     bool getEtat(); //fonction qui donne l'etat de la connexion
private:
    Ui::connexion *ui;
    database *maDb;
private:
    QString getNom(); // fonction qui retroune le nom entré
    QString getMdp();// fonction qui retourne le mdp entré
    bool etatConnec; //etat qui dit si l'on est bien connecté Vrai si connecté faux si non connecté


public slots:
     void confirmerConnec(); // slot qui comfirme la connxion après s'être identifié

};

#endif // CONNEXION_H
