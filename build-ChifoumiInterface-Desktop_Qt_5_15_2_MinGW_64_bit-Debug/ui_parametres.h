/********************************************************************************
** Form generated from reading UI file 'parametres.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETRES_H
#define UI_PARAMETRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_parametres
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lNom;
    QLineEdit *eNom;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lMaxPoints;
    QLineEdit *ePoints;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lTemps;
    QLineEdit *eSecondes;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *bOk;

    void setupUi(QDialog *parametres)
    {
        if (parametres->objectName().isEmpty())
            parametres->setObjectName(QString::fromUtf8("parametres"));
        parametres->resize(211, 148);
        verticalLayout_2 = new QVBoxLayout(parametres);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lNom = new QLabel(parametres);
        lNom->setObjectName(QString::fromUtf8("lNom"));

        horizontalLayout->addWidget(lNom);

        eNom = new QLineEdit(parametres);
        eNom->setObjectName(QString::fromUtf8("eNom"));

        horizontalLayout->addWidget(eNom);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lMaxPoints = new QLabel(parametres);
        lMaxPoints->setObjectName(QString::fromUtf8("lMaxPoints"));

        horizontalLayout_3->addWidget(lMaxPoints);

        ePoints = new QLineEdit(parametres);
        ePoints->setObjectName(QString::fromUtf8("ePoints"));

        horizontalLayout_3->addWidget(ePoints);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lTemps = new QLabel(parametres);
        lTemps->setObjectName(QString::fromUtf8("lTemps"));

        horizontalLayout_2->addWidget(lTemps);

        eSecondes = new QLineEdit(parametres);
        eSecondes->setObjectName(QString::fromUtf8("eSecondes"));

        horizontalLayout_2->addWidget(eSecondes);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        bOk = new QDialogButtonBox(parametres);
        bOk->setObjectName(QString::fromUtf8("bOk"));
        bOk->setOrientation(Qt::Horizontal);
        bOk->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(bOk);


        retranslateUi(parametres);
        QObject::connect(bOk, SIGNAL(accepted()), parametres, SLOT(accept()));
        QObject::connect(bOk, SIGNAL(rejected()), parametres, SLOT(reject()));

        QMetaObject::connectSlotsByName(parametres);
    } // setupUi

    void retranslateUi(QDialog *parametres)
    {
        parametres->setWindowTitle(QCoreApplication::translate("parametres", "Dialog", nullptr));
        lNom->setText(QCoreApplication::translate("parametres", "Nom :", nullptr));
        eNom->setText(QCoreApplication::translate("parametres", "Vous", nullptr));
        lMaxPoints->setText(QCoreApplication::translate("parametres", "Max. de points :", nullptr));
        ePoints->setText(QCoreApplication::translate("parametres", "5", nullptr));
        lTemps->setText(QCoreApplication::translate("parametres", "Temps max. (s)  :", nullptr));
        eSecondes->setText(QCoreApplication::translate("parametres", "30", nullptr));
    } // retranslateUi

};

namespace Ui {
    class parametres: public Ui_parametres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETRES_H
