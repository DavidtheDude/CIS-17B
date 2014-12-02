#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include "battlearea.h"
class movement
{
public:
    movement();
    void keybinds();
    void moveBy(int x, int y);
protected:
    virtual void keyPressEvent(QKeyEvent *event);

};

#endif // MOVEMENT_H
