#ifndef BATTLEAREA_H
#define BATTLEAREA_H

#include <QWidget>
#include <QXmlStreamReader>
#include <QFile>
#include <QPixmap>
namespace Ui {
class BattleArea;
}

class BattleArea : public QWidget
{
    Q_OBJECT

public:
    explicit BattleArea(QWidget *parent = 0);
    ~BattleArea();
    void Load();

private:
    Ui::BattleArea *ui;
};

#endif // BATTLEAREA_H
