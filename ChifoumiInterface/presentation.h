#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "chifoumi.h"
#include "chifoumivue.h"
#include "QTimer"

class presentation : public QObject
{
    Q_OBJECT
public:
    explicit presentation(QObject *parent = nullptr);
private:
    int tps;
    bool pause;
public:
    Chifoumi* getChifoumi();
    ChifoumiVue* getchifoumiVue();
    void setChifoumi(Chifoumi *m);
    void setVue(ChifoumiVue *v);
public slots:
    void envoieCiseau();
    void envoiePierre();
    void envoiePapier();
    void nouvellePartie();
    void aPropos();
    void compteRebours();
    void pauseCompteur();
private:
    Chifoumi *LeModele;
    ChifoumiVue *laVue;
};

#endif // PRESENTATION_H
