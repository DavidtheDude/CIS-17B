#include "movement.h"

movement::movement()
{
}

void movement::keybinds()
{

}

void movement::moveBy(int x, int y)
{

}

void movement::keyPressEvent(QKeyEvent *event)
{
    switch( event->key ){
        case Qt::Key_Right:{
            moveBy(30,0);
            break;
        }
        case Qt::Key_Left:{
            moveBy(-30,0);
            break;
        }
        case Qt::Key_Up:{
            moveBy(0,30);
            break;
        }
        case Qt::Key_Down:{
            moveBy(0,-30);
            break;
        }

    }
    repaint();
}
