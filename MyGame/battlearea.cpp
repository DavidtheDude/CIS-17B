#include "battlearea.h"
#include "ui_battlearea.h"

BattleArea::BattleArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BattleArea)
{
    ui->setupUi(this);
}

BattleArea::~BattleArea()
{
    delete ui;
}

void BattleArea::Load()
{
    QFile zeroDashFile("qrc:/Zero/dash.xml");
    zeroDashFile.open(QIODevice::ReadOnly);
    QXmlStreamReader zeroDash(&zeroDashFile);
    while (!zeroDash.atEnd()) {
             zeroDash.readNext();
             // do processing
       }

}
