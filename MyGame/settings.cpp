#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QString>
Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    QString filename="config.txt";
    QFile mFile(filename);
    if(mFile.open(QFile::ReadOnly|QFile::Text)){
       QTextStream out(&mFile);
       QString k=out.readLine();
       QStringList y=k.split(":", QString::SkipEmptyParts);

       ui->Difficulty->setValue(y[1].toInt());
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->FOV->setText(y[1]);
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->FramRateCap->setText(y[1]);
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->Cap->setValue(y[1].toInt());
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->DisplayFPS->setChecked(y[1].toInt());
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->FullScreen->setChecked(y[1].toInt());
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->Windowed->setChecked(y[1].toInt());
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->Resolution->setValue(y[1].toInt());
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->Up->setText(y[1]);
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->Down->setText(y[1]);
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->Left->setText(y[1]);
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->Right->setText(y[1]);
       k.clear();
       y.clear();

       k=out.readLine();
       y=k.split(":", QString::SkipEmptyParts);
       ui->Jump->setText(y[1]);
       k.clear();
       y.clear();

    }
    mFile.close();

}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_Back_clicked()
{
    MainWindow *k=new MainWindow;
    k->show();
    this->close();
}

void Settings::on_Save_clicked()
{
    QString filename="config.txt";
    QFile eFile(filename);
    if(eFile.open(QFile::WriteOnly|QFile::Text)){
        QTextStream out(&eFile);
        out<<"DIFFICULTY: "     <<ui->Difficulty->text()<<endl;
        out<<"FOV: "            <<ui->FOV->text()<<endl;
        out<<"FRAMERATE: "      <<ui->FramRateCap->isChecked()<<endl;
        out<<"CAP: "            <<ui->Cap->text()<<endl;
        out<<"DISPLAYFPS: "     <<ui->DisplayFPS->isChecked()<<endl;
        out<<"FULLSCREEN: "     <<ui->FullScreen->isChecked()<<endl;
        out<<"WINDOWED: "       <<ui->Windowed->isChecked()<<endl;
        out<<"RESOLUTION: "     <<ui->Resolution->text()<<endl;
        out<<"UP: "             <<ui->Up->text()<<endl;
        out<<"DOWN: "           <<ui->Down->text()<<endl;
        out<<"LEFT: "           <<ui->Left->text()<<endl;
        out<<"RIGHT: "          <<ui->Right->text()<<endl;
        out<<"JUMP: "           <<ui->Jump->text()<<endl;

    }

    eFile.close();

}
