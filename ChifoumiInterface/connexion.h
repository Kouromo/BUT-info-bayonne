#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>
#include "database.h"

namespace Ui {
class connexion;
}

class connexion : public QDialog
{
    Q_OBJECT

public:
    explicit connexion(QWidget *parent = nullptr);
    ~connexion();
public:
      bool verifConnexion(); // Slot qui quand on appuie sur le bouton vérifie que l'utilisateur existe et si oui accède au jeu.

private:
    Ui::connexion *ui;
    database *maDb;
private:
    QString getNom();
    QString getMdp();


};

#endif // CONNEXION_H
