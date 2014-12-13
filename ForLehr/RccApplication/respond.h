#ifndef RESPOND_H
#define RESPOND_H

#include <QWidget>
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class Respond;
}

class Respond : public QWidget
{
    Q_OBJECT

public:
    explicit Respond(QWidget *parent = 0);
    ~Respond();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Respond *ui;
};

#endif // RESPOND_H
