#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "battlearea.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/background.jpg");
    bkgnd=bkgnd.scaled(this->size(), Qt::KeepAspectRatioByExpanding);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Settings_clicked()
{
    Settings *k= new Settings;
    k->show();
    this->close();
}

void MainWindow::on_Exit_clicked()
{
    this->close();
}

void MainWindow::on_NewGame_clicked()
{
    BattleArea *k = new BattleArea;
    k->show();
    this->close();
}
