#include "thread.h"
#include "ui_thread.h"

Thread::Thread(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Thread)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

Thread::~Thread()
{
    delete ui;
}

void Thread::on_pushButton_clicked()
{
    Respond *k = new Respond;
    k->show();
}
