#ifndef SUBFORUM_H
#define SUBFORUM_H

#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include "thread.h"



namespace Ui {
class SubForum;
}

class SubForum : public QWidget
{
    Q_OBJECT

public:
    explicit SubForum(QString, QWidget *parent = 0);
    ~SubForum();
    void writeName(QString );
    void doStuff();
private slots:
    void showThread();

private:
    Ui::SubForum *ui;
    QString name;
};

#endif // SUBFORUM_H
