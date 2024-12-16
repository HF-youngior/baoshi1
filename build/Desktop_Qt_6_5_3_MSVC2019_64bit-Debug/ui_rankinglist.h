/********************************************************************************
** Form generated from reading UI file 'rankinglist.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKINGLIST_H
#define UI_RANKINGLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RankingList
{
public:
    QPushButton *back;
    QTableWidget *rankingTableWidget;

    void setupUi(QWidget *RankingList)
    {
        if (RankingList->objectName().isEmpty())
            RankingList->setObjectName("RankingList");
        RankingList->resize(458, 572);
        back = new QPushButton(RankingList);
        back->setObjectName("back");
        back->setGeometry(QRect(330, 520, 80, 24));
        rankingTableWidget = new QTableWidget(RankingList);
        rankingTableWidget->setObjectName("rankingTableWidget");
        rankingTableWidget->setGeometry(QRect(20, 50, 391, 431));

        retranslateUi(RankingList);

        QMetaObject::connectSlotsByName(RankingList);
    } // setupUi

    void retranslateUi(QWidget *RankingList)
    {
        RankingList->setWindowTitle(QCoreApplication::translate("RankingList", "Form", nullptr));
        back->setText(QCoreApplication::translate("RankingList", "back ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankingList: public Ui_RankingList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKINGLIST_H
