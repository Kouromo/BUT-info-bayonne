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
      bool verifConnexion(); // fonction qui va vérfier quand on quitte le dialogue si on est bien connecté.

private:
    Ui::connexion *ui;
    database *maDb;
private:
    QString getNom(); // fonction qui retroune le nom entré
    QString getMdp();// fonction qui retourne le mdp entré


};

#endif // CONNEXION_H
