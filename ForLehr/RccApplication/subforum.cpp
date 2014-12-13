#include "subforum.h"
#include "ui_subforum.h"



SubForum::SubForum(QString sName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubForum)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    writeName(sName);
    doStuff();
}

SubForum::~SubForum()
{
    delete ui;
}

void SubForum::writeName(QString sName)
{
    name = sName;
}

void SubForum::doStuff()
{
    ui->label->setText(name);
    /*
    QPushButton *a = new QPushButton[26];
    for(int i=1; i<=4; i++){
        for(int k=1; k<=26; k++){
            ui->tableWidget->setCellWidget(k,i, a[k-1]);
        }

    }

    */
    connect( ui->tableWidget , SIGNAL( cellClicked(int,int) ), this, SLOT( showThread() ) );



}

void SubForum::showThread()
{
    Thread *k = new Thread;
    k->show();
}
