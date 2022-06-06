#include "chifoumivue.h"
#include "chifoumi.h"
#include "presentation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chifoumi *m= new Chifoumi();
    presentation *p= new presentation();
    ChifoumiVue w;
    // mise en oeuvre du modèle MVP
    // La présentation pointe sur le modèle et la vue
    p->setVue(&w);
    p->setChifoumi(m);

    // La Vue pointe sur la présentation
    w.nvelleConnexion(p);

    //p->getchifoumiVue()->miseAJourInterface(Chifoumi::rien, Chifoumi::rien);

    w.miseAJourInterface(Chifoumi::rien, Chifoumi::rien);
    w.show();
    connexion *connec= new connexion;
    do
    {
           connec->exec();
    }
    while(!connec->verifConnexion());


    return a.exec();
}
