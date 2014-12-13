#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "homescreen.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = 0);
    ~LoginPage();

private slots:
    void on_Login_clicked();

    void on_CreateAcc_clicked();

    void on_X_clicked();

    void on___clicked();

private:
    Ui::LoginPage *ui;

    void splashInit();

    QString email,password;

    bool checke, checkp;

    QGraphicsScene *scene;
};

#endif // LOGINPAGE_H
