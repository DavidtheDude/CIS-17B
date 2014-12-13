#ifndef THREAD_H
#define THREAD_H

#include <QWidget>

#include "respond.h"

namespace Ui {
class Thread;
}

class Thread : public QWidget
{
    Q_OBJECT

public:
    explicit Thread(QWidget *parent = 0);
    ~Thread();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Thread *ui;
};

#endif // THREAD_H
