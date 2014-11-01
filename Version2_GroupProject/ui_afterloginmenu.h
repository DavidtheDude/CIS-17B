/********************************************************************************
** Form generated from reading UI file 'afterloginmenu.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFTERLOGINMENU_H
#define UI_AFTERLOGINMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AfterLoginMenu
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *AfterLoginMenu)
    {
        if (AfterLoginMenu->objectName().isEmpty())
            AfterLoginMenu->setObjectName(QString::fromUtf8("AfterLoginMenu"));
        AfterLoginMenu->resize(400, 300);
        pushButton = new QPushButton(AfterLoginMenu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 75, 23));
        pushButton_2 = new QPushButton(AfterLoginMenu);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 260, 75, 23));
        pushButton_3 = new QPushButton(AfterLoginMenu);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 70, 75, 23));
        pushButton_4 = new QPushButton(AfterLoginMenu);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 110, 75, 23));
        pushButton_5 = new QPushButton(AfterLoginMenu);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 150, 75, 23));
        pushButton_6 = new QPushButton(AfterLoginMenu);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(310, 10, 81, 23));

        retranslateUi(AfterLoginMenu);

        QMetaObject::connectSlotsByName(AfterLoginMenu);
    } // setupUi

    void retranslateUi(QWidget *AfterLoginMenu)
    {
        AfterLoginMenu->setWindowTitle(QApplication::translate("AfterLoginMenu", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AfterLoginMenu", "News", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AfterLoginMenu", "Logout", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("AfterLoginMenu", "Classes", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("AfterLoginMenu", "Information", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("AfterLoginMenu", "Forum", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("AfterLoginMenu", "Delete Account", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AfterLoginMenu: public Ui_AfterLoginMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFTERLOGINMENU_H
