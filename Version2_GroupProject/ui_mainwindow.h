/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEmail;
    QLineEdit *linePassword;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuNo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(230, 290, 321, 91));
        lineEmail = new QLineEdit(groupBox);
        lineEmail->setObjectName(QString::fromUtf8("lineEmail"));
        lineEmail->setGeometry(QRect(90, 20, 113, 20));
        lineEmail->setAutoFillBackground(false);
        lineEmail->setAlignment(Qt::AlignCenter);
        linePassword = new QLineEdit(groupBox);
        linePassword->setObjectName(QString::fromUtf8("linePassword"));
        linePassword->setGeometry(QRect(90, 50, 113, 20));
        linePassword->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 20, 46, 13));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 50, 46, 13));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(214, 20, 101, 23));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(214, 50, 101, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(230, 390, 321, 61));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 20, 111, 23));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(180, 20, 121, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuNo = new QMenu(menuBar);
        menuNo->setObjectName(QString::fromUtf8("menuNo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuNo->menuAction());
        menuNo->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        lineEmail->setPlaceholderText(QApplication::translate("MainWindow", "Email", 0, QApplication::UnicodeUTF8));
        linePassword->setPlaceholderText(QApplication::translate("MainWindow", "Password", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Email", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Password", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Forgot Password", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "New User", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Create New Account", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Something Else", 0, QApplication::UnicodeUTF8));
        menuNo->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
