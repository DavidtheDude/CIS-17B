/********************************************************************************
** Form generated from reading UI file 'forgot.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOT_H
#define UI_FORGOT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Forgot
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Forgot)
    {
        if (Forgot->objectName().isEmpty())
            Forgot->setObjectName(QString::fromUtf8("Forgot"));
        Forgot->resize(400, 300);
        pushButton = new QPushButton(Forgot);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 110, 75, 23));
        lineEdit = new QLineEdit(Forgot);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 110, 113, 20));

        retranslateUi(Forgot);

        QMetaObject::connectSlotsByName(Forgot);
    } // setupUi

    void retranslateUi(QWidget *Forgot)
    {
        Forgot->setWindowTitle(QApplication::translate("Forgot", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Forgot", "Send Email", 0, QApplication::UnicodeUTF8));
        lineEdit->setPlaceholderText(QApplication::translate("Forgot", "Email", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Forgot: public Ui_Forgot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOT_H
