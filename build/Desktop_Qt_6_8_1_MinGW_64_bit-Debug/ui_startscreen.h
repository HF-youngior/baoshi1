/********************************************************************************
** Form generated from reading UI file 'startscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTSCREEN_H
#define UI_STARTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartScreen
{
public:
    QPushButton *pushButton;
    QFrame *frame;
    QToolButton *toolButton;
    QFrame *line;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;

    void setupUi(QWidget *StartScreen)
    {
        if (StartScreen->objectName().isEmpty())
            StartScreen->setObjectName("StartScreen");
        StartScreen->resize(900, 585);
        pushButton = new QPushButton(StartScreen);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(730, 100, 91, 91));
        frame = new QFrame(StartScreen);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(370, 10, 421, 501));
        frame->setCursor(QCursor(Qt::CursorShape::OpenHandCursor));
        frame->setMouseTracking(false);
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Sunken);
        toolButton = new QToolButton(frame);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(390, 10, 25, 23));
        line = new QFrame(frame);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 80, 421, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName("toolButton_3");
        toolButton_3->setGeometry(QRect(40, 210, 80, 24));
        toolButton_4 = new QToolButton(frame);
        toolButton_4->setObjectName("toolButton_4");
        toolButton_4->setGeometry(QRect(260, 210, 80, 24));
        toolButton_5 = new QToolButton(frame);
        toolButton_5->setObjectName("toolButton_5");
        toolButton_5->setGeometry(QRect(40, 330, 80, 24));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 120, 61, 61));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/image/3.1.jpg);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(270, 130, 61, 61));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/image/3.2.jpg);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 260, 61, 61));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/image/3.3.jpg);"));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(310, 460, 91, 21));
        toolButton->raise();
        line->raise();
        label->raise();
        toolButton_3->raise();
        label_3->raise();
        toolButton_5->raise();
        label_2->raise();
        toolButton_4->raise();
        label_4->raise();
        pushButton_2 = new QPushButton(StartScreen);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(70, 440, 80, 24));

        retranslateUi(StartScreen);
        QObject::connect(pushButton, &QPushButton::clicked, frame, qOverload<>(&QFrame::show));
        QObject::connect(toolButton, &QToolButton::clicked, frame, qOverload<>(&QFrame::close));

        QMetaObject::connectSlotsByName(StartScreen);
    } // setupUi

    void retranslateUi(QWidget *StartScreen)
    {
        StartScreen->setWindowTitle(QCoreApplication::translate("StartScreen", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("StartScreen", "\351\201\223\345\205\267\345\225\206\345\272\227", nullptr));
        toolButton->setText(QCoreApplication::translate("StartScreen", "X", nullptr));
        toolButton_3->setText(QCoreApplication::translate("StartScreen", "\351\207\215\347\275\256\350\215\257\346\260\264", nullptr));
        toolButton_4->setText(QCoreApplication::translate("StartScreen", "\346\227\266\351\227\264\346\232\202\345\201\234\350\215\257\346\260\264", nullptr));
        toolButton_5->setText(QCoreApplication::translate("StartScreen", "\350\266\205\347\272\247\350\215\257\346\260\264", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("StartScreen", "\344\275\231\351\242\235\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StartScreen", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartScreen: public Ui_StartScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTSCREEN_H
