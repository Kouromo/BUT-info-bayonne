#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H
#include "chifoumi.h"
#include <QMainWindow>
#include <cstdlib>

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();
public slots:
    void envoieCiseau();
    void envoiePierre();
    void envoiePapier();
    void nouvellePartie();

public:
    void miseAJourInterface(Chifoumi::UnCoup, Chifoumi::UnCoup);


private:
    Ui::ChifoumiVue *ui;
    Chifoumi LaPartie;
};
#endif // CHIFOUMIVUE_H
