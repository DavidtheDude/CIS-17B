#include <QtGui>
#include <QtCore>
#include "createaccount.h"
#include "ui_createaccount.h"
#include "io.h"

CreateAccount::CreateAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAccount)
{
    ui->setupUi(this);
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

/**
 * when the create account button is clicked
 * @brief CreateAccount::on_createButton_clicked
 */
void CreateAccount::on_createButton_clicked(){
    QString email = ui->email->text();
    QString pass = ui->password->text();
    QString confPass = ui->confirmPassword->text();
    bool canProceed = true;

    if( !email.contains( QRegExp( "[\\w|.|-]*@\\w*\\.[\\w|.]*" ) ) ){
        alert( "Invalid Email", "Enter a valid email" );
        canProceed = false;
        return;
    }

    if( pass != confPass ){
        alert( "Mismatching Password", "Passwords do not match" );
        canProceed = false;
        return;
    }

    if( canProceed ){
        IO io;
        QByteArray passHash = QCryptographicHash::hash( pass.toUtf8(), QCryptographicHash::Sha1 );
        QString passSha = passHash.toHex();
        io.saveUser( email, passSha );
        this->close();
    }
}

/**
 * tired of making these information things
 * @brief CreateAccount::alert
 * @param title
 * @param msg
 */
void CreateAccount::alert( QString title, QString msg ){
    QMessageBox::information(this, title, msg );
}


void CreateAccount::on_cancelButton_clicked() {
    close();
}
