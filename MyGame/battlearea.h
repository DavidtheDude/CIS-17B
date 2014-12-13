#ifndef BATTLEAREA_H
#define BATTLEAREA_H

#include <QWidget>
#include <QFile>
#include <QPixmap>
#include <QtXml/QDomElement>
#include <QDebug>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>
#include <QTimer>
#include <QObject>
#include <QPainter>
#include <QElapsedTimer>
#include <QImage>
#include <QtGui>

#include "myitem.h"

namespace Ui {
class BattleArea;
}

class BattleArea : public QWidget
{
    Q_OBJECT

public:
    explicit BattleArea(QWidget *parent = 0);
    ~BattleArea();

    bool counter();


protected:
    void paintEvent(QPaintEvent *);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    void getFilePaths();
    void load(QString File);
    void advance(int);
public slots:
    void nextFrame();
private:
    enum Direction{
        Left,
        Right
    };
    enum Move{
        run,
        dash,
        W_Smash,
        S_Smash
    };
    Ui::BattleArea *ui;
    QPixmap Run[100];
    QPixmap SSmash[100];
    QPixmap MSmash[100];
    QPixmap WSmash[100];
    QPixmap Dash[100];
    QPixmap iSprites[100];
    QPoint offsetPoints[100];
    QPoint offsetPointsDash[100];
    QPoint offsetPointsRun[100];
    QPoint offsetPointsMSmash[100];
    QPoint offsetPointsSSmash[100];
    QPoint offsetPointsWSmash[100];
    int x;
    int y;
    // 1 Run, 2 Dash, 3 SSmash, 4WSmash
    int tempSize;
    int size[4];
    int i;
    int tracker;
    QTimer *timer;
    QTimer *timer2;
    QPainter paint;
    QImage flipped;
    Direction player1;
    Direction currentDirectionP1;
    Move control;
    //QGraphicsScene *scene;
    //QStringList filePathList;
};

#endif // BATTLEAREA_H
