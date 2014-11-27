#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QFile>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private slots:
    void on_Back_clicked();

    void on_Save_clicked();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
