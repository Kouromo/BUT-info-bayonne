/********************************************************************************
** Form generated from reading UI file 'connexion.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNEXION_H
#define UI_CONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_connexion
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lIdenifiant;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lMdp;
    QHBoxLayout *horizontalLayout;
    QPushButton *QConfirm;

    void setupUi(QDialog *connexion)
    {
        if (connexion->objectName().isEmpty())
            connexion->setObjectName(QString::fromUtf8("connexion"));
        connexion->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(connexion);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(connexion);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(connexion);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lIdenifiant = new QLineEdit(connexion);
        lIdenifiant->setObjectName(QString::fromUtf8("lIdenifiant"));

        horizontalLayout_2->addWidget(lIdenifiant);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(connexion);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lMdp = new QLineEdit(connexion);
        lMdp->setObjectName(QString::fromUtf8("lMdp"));

        horizontalLayout_3->addWidget(lMdp);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        QConfirm = new QPushButton(connexion);
        QConfirm->setObjectName(QString::fromUtf8("QConfirm"));

        horizontalLayout->addWidget(QConfirm);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(connexion);
        QObject::connect(QConfirm, SIGNAL(clicked()), connexion, SLOT(close()));

        QMetaObject::connectSlotsByName(connexion);
    } // setupUi

    void retranslateUi(QDialog *connexion)
    {
        connexion->setWindowTitle(QCoreApplication::translate("connexion", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("connexion", "Connectez-vous pour jouer!", nullptr));
        label->setText(QCoreApplication::translate("connexion", "Identifant : ", nullptr));
        label_2->setText(QCoreApplication::translate("connexion", "Mot de passe :", nullptr));
        QConfirm->setText(QCoreApplication::translate("connexion", "Confirmer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class connexion: public Ui_connexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNEXION_H
