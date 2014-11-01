/********************************************************************************
** Form generated from reading UI file 'confirm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRM_H
#define UI_CONFIRM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Confirm
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Confirm)
    {
        if (Confirm->objectName().isEmpty())
            Confirm->setObjectName(QString::fromUtf8("Confirm"));
        Confirm->resize(400, 300);
        label = new QLabel(Confirm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 110, 121, 41));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Confirm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 190, 75, 23));
        pushButton_2 = new QPushButton(Confirm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 220, 75, 23));

        retranslateUi(Confirm);

        QMetaObject::connectSlotsByName(Confirm);
    } // setupUi

    void retranslateUi(QWidget *Confirm)
    {
        Confirm->setWindowTitle(QApplication::translate("Confirm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Confirm", "Are you sure?", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Confirm", "Confirm", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Confirm", "No", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Confirm: public Ui_Confirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRM_H
