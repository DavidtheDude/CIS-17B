/********************************************************************************
** Form generated from reading UI file 'newaccount.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWACCOUNT_H
#define UI_NEWACCOUNT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewAccount
{
public:
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox_4;
    QLineEdit *lineEdit_5;
    QLabel *label_5;

    void setupUi(QWidget *NewAccount)
    {
        if (NewAccount->objectName().isEmpty())
            NewAccount->setObjectName(QString::fromUtf8("NewAccount"));
        NewAccount->resize(400, 300);
        pushButton = new QPushButton(NewAccount);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 240, 75, 23));
        pushButton->setFocusPolicy(Qt::NoFocus);
        groupBox = new QGroupBox(NewAccount);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 351, 51));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 20, 120, 20));
        lineEdit->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 46, 13));
        groupBox_2 = new QGroupBox(NewAccount);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 60, 351, 41));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 10, 120, 20));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 10, 46, 13));
        groupBox_3 = new QGroupBox(NewAccount);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 100, 351, 80));
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 20, 120, 20));
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(100, 50, 120, 20));
        lineEdit_4->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 20, 46, 13));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 50, 46, 13));
        groupBox_4 = new QGroupBox(NewAccount);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 180, 351, 51));
        lineEdit_5 = new QLineEdit(groupBox_4);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(100, 20, 120, 20));
        lineEdit_5->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 20, 46, 13));

        retranslateUi(NewAccount);

        QMetaObject::connectSlotsByName(NewAccount);
    } // setupUi

    void retranslateUi(QWidget *NewAccount)
    {
        NewAccount->setWindowTitle(QApplication::translate("NewAccount", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("NewAccount", "Sign Up", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NewAccount", "Username", 0, QApplication::UnicodeUTF8));
        lineEdit->setPlaceholderText(QApplication::translate("NewAccount", "Username", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewAccount", "Username", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NewAccount", "Email", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setPlaceholderText(QApplication::translate("NewAccount", "Email", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewAccount", "Email", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("NewAccount", "Password", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setPlaceholderText(QApplication::translate("NewAccount", "Password", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setPlaceholderText(QApplication::translate("NewAccount", "Confirm Password", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewAccount", "Password", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewAccount", "Confirm", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("NewAccount", "Phone", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setPlaceholderText(QApplication::translate("NewAccount", "Phone Number", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NewAccount", "Phone", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewAccount: public Ui_NewAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWACCOUNT_H
