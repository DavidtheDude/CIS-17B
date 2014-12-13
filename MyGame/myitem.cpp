#include "myitem.h"

MyItem::MyItem()
{
    angle = (qrand() % 360);
    setRotation(angle);

    speed = 5;

    int StartX = 0;
    int StartY = 0;

    if(qrand()%1){
        StartX = (qrand() % 100);
        StartY = (qrand() % 100);
    }else{
        StartX = (qrand() % -50);
        StartY = (qrand() % -50);
    }
    setPos(mapToParent(StartX,StartY));
}

QRectF MyItem::boundingRect() const
{
    return QRect(0,0,20,20);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush(Qt::gray);

    if(scene()->collidingItems(this).isEmpty()){
        //no collision
        Brush.setColor(Qt::green);
    }else{
        //collision
        Brush.setColor(Qt::red);
        DoCollision();
    }
    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}

void MyItem::advance(int phase)
{
    if(!phase) return;

    QPointF location = this->pos();

    setPos(mapToParent(0, -(speed)));
}

void MyItem::DoCollision()
{
    if(((qrand()%1))){
        setRotation(rotation()+(180+(qrand()%10)));
    }else{
        setRotation(rotation()+(180+(qrand()%-10)));
    }
    QPointF newPoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() +2));
    if(!scene()->sceneRect().contains(newPoint)){
        //move it back
        newPoint = mapToParent(0,0);
    }else{
        //set new pos
        setPos(newPoint);
    }

}
