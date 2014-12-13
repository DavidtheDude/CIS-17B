#include "zero.h"

Zero::Zero()
{
    Run = new QPixmap[100];
    SSmash = new QPixmap[100];
    MSmash = new QPixmap[100];
    WSmash = new QPixmap[100];
    Dash = new QPixmap[100];
    offsetPointsDash = new QPoint[100];
    offsetPointsSSmash = new QPoint[100];
    offsetPointsRun = new QPoint[100];
    offsetPointsWSmash = new QPoint[100];
    offsetPointsMSmash = new QPoint[100];

}
