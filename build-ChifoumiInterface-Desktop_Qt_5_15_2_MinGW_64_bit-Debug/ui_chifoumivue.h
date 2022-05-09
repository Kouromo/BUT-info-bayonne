/********************************************************************************
** Form generated from reading UI file 'chifoumivue.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIFOUMIVUE_H
#define UI_CHIFOUMIVUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChifoumiVue
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *hPrincipal;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *lMachine;
    QLabel *lJoueur;
    QLabel *lScoreMachine;
    QHBoxLayout *hLayoutDuel;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lImageDuel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lScoreJoueur;
    QSpacerItem *horizontalSpacer;
    QLabel *lFigureMachine;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lFigureJoueur;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hFigures;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *bPierre;
    QPushButton *bPapier;
    QPushButton *bCiseau;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *bNewGame;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuAide;

    void setupUi(QMainWindow *ChifoumiVue)
    {
        if (ChifoumiVue->objectName().isEmpty())
            ChifoumiVue->setObjectName(QString::fromUtf8("ChifoumiVue"));
        ChifoumiVue->resize(340, 360);
        ChifoumiVue->setMinimumSize(QSize(340, 360));
        centralwidget = new QWidget(ChifoumiVue);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hPrincipal = new QHBoxLayout();
        hPrincipal->setObjectName(QString::fromUtf8("hPrincipal"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lMachine = new QLabel(centralwidget);
        lMachine->setObjectName(QString::fromUtf8("lMachine"));

        gridLayout_2->addWidget(lMachine, 0, 3, 1, 1, Qt::AlignHCenter);

        lJoueur = new QLabel(centralwidget);
        lJoueur->setObjectName(QString::fromUtf8("lJoueur"));

        gridLayout_2->addWidget(lJoueur, 0, 0, 1, 1, Qt::AlignHCenter);

        lScoreMachine = new QLabel(centralwidget);
        lScoreMachine->setObjectName(QString::fromUtf8("lScoreMachine"));

        gridLayout_2->addWidget(lScoreMachine, 1, 3, 1, 1, Qt::AlignHCenter);

        hLayoutDuel = new QHBoxLayout();
        hLayoutDuel->setObjectName(QString::fromUtf8("hLayoutDuel"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutDuel->addItem(horizontalSpacer_4);

        lImageDuel = new QLabel(centralwidget);
        lImageDuel->setObjectName(QString::fromUtf8("lImageDuel"));
        lImageDuel->setMaximumSize(QSize(50, 50));
        lImageDuel->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/versus_70.png")));
        lImageDuel->setScaledContents(true);

        hLayoutDuel->addWidget(lImageDuel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutDuel->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(hLayoutDuel, 2, 2, 1, 1);

        lScoreJoueur = new QLabel(centralwidget);
        lScoreJoueur->setObjectName(QString::fromUtf8("lScoreJoueur"));

        gridLayout_2->addWidget(lScoreJoueur, 1, 0, 1, 1, Qt::AlignHCenter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        lFigureMachine = new QLabel(centralwidget);
        lFigureMachine->setObjectName(QString::fromUtf8("lFigureMachine"));
        lFigureMachine->setMaximumSize(QSize(80, 80));
        lFigureMachine->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/rien_115.png")));
        lFigureMachine->setScaledContents(true);

        gridLayout_2->addWidget(lFigureMachine, 2, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        lFigureJoueur = new QLabel(centralwidget);
        lFigureJoueur->setObjectName(QString::fromUtf8("lFigureJoueur"));
        lFigureJoueur->setMaximumSize(QSize(80, 80));
        lFigureJoueur->setPixmap(QPixmap(QString::fromUtf8(":/chifoumi/rien_115.png")));
        lFigureJoueur->setScaledContents(true);

        gridLayout_2->addWidget(lFigureJoueur, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        hFigures = new QHBoxLayout();
        hFigures->setObjectName(QString::fromUtf8("hFigures"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_7 = new QHBoxLayout(groupBox);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        bPierre = new QPushButton(groupBox);
        bPierre->setObjectName(QString::fromUtf8("bPierre"));
        bPierre->setEnabled(true);
        bPierre->setMinimumSize(QSize(80, 80));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/chifoumi/pierre_115.png"), QSize(), QIcon::Normal, QIcon::Off);
        bPierre->setIcon(icon);
        bPierre->setIconSize(QSize(80, 80));
        bPierre->setCheckable(false);

        horizontalLayout_7->addWidget(bPierre);

        bPapier = new QPushButton(groupBox);
        bPapier->setObjectName(QString::fromUtf8("bPapier"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/chifoumi/papier_115.png"), QSize(), QIcon::Normal, QIcon::Off);
        bPapier->setIcon(icon1);
        bPapier->setIconSize(QSize(80, 80));

        horizontalLayout_7->addWidget(bPapier);

        bCiseau = new QPushButton(groupBox);
        bCiseau->setObjectName(QString::fromUtf8("bCiseau"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/chifoumi/ciseau_115.png"), QSize(), QIcon::Normal, QIcon::Off);
        bCiseau->setIcon(icon2);
        bCiseau->setIconSize(QSize(80, 80));

        horizontalLayout_7->addWidget(bCiseau);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        hFigures->addWidget(groupBox);


        verticalLayout_2->addLayout(hFigures);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        bNewGame = new QPushButton(centralwidget);
        bNewGame->setObjectName(QString::fromUtf8("bNewGame"));

        horizontalLayout->addWidget(bNewGame, 0, Qt::AlignRight);


        verticalLayout_2->addLayout(horizontalLayout);


        hPrincipal->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(hPrincipal);

        ChifoumiVue->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChifoumiVue);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 340, 20));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        ChifoumiVue->setMenuBar(menubar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuAide->menuAction());

        retranslateUi(ChifoumiVue);

        QMetaObject::connectSlotsByName(ChifoumiVue);
    } // setupUi

    void retranslateUi(QMainWindow *ChifoumiVue)
    {
        ChifoumiVue->setWindowTitle(QCoreApplication::translate("ChifoumiVue", "ChifoumiVue", nullptr));
        lMachine->setText(QCoreApplication::translate("ChifoumiVue", "Machine", nullptr));
        lJoueur->setText(QCoreApplication::translate("ChifoumiVue", "Vous", nullptr));
        lScoreMachine->setText(QCoreApplication::translate("ChifoumiVue", "0", nullptr));
        lImageDuel->setText(QString());
        lScoreJoueur->setText(QCoreApplication::translate("ChifoumiVue", "0", nullptr));
        lFigureMachine->setText(QString());
        lFigureJoueur->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("ChifoumiVue", "Choisissez une figure :", nullptr));
        bPierre->setText(QString());
        bPapier->setText(QString());
        bCiseau->setText(QString());
        bNewGame->setText(QCoreApplication::translate("ChifoumiVue", "Nouvelle Partie", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("ChifoumiVue", "Fichier", nullptr));
        menuAide->setTitle(QCoreApplication::translate("ChifoumiVue", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChifoumiVue: public Ui_ChifoumiVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIFOUMIVUE_H
