#ifndef BATTLEAREA_H
#define BATTLEAREA_H

#include <QWidget>
#include <QXmlStreamReader>
#include <QFile>
#include <QPixmap>
#include <QtXml/QDomElement>
#include <QDebug>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>
#include <QList>
#include <QTime>
#include <QTimer>
#include <QGraphicsObject>
#include <QObject>
#include <QPainter>
#include <QElapsedTimer>
#include <QtCore/qpropertyanimation.h>


#include "animation.h"
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
    void instantiateTimer();
    void runAnimation();
    void startAnimation();

protected:
    void paintEvent(QPaintEvent *);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
public slots:
    void nextFrame();
private:
    Ui::BattleArea *ui;
    QPixmap *iSprites = new QPixmap[100];
    QPoint *offsetPoints = new QPoint[100];
    int x=400;
    int y=300;
    int size;
    int i=0;
    QTimer *timer = new QTimer;
    Animation *m_anim;
};

#endif // BATTLEAREA_H
