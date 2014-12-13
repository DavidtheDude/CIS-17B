#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = 0);
    ~CreateAccount();

private slots:
    void on_createButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CreateAccount *ui;
    void alert( QString, QString );
};

#endif // CREATEACCOUNT_H
