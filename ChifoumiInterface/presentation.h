#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "chifoumi.h"
#include "chifoumivue.h"
class presentation : public QObject
{
    Q_OBJECT
public:
    explicit presentation(QObject *parent = nullptr);
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
private:
    Chifoumi *LeModele;
    ChifoumiVue *laVue;
};

#endif // PRESENTATION_H
