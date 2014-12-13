#ifndef ZERO_H
#define ZERO_H
#include <QtCore>
#include <QPixmap>

class Zero
{
public:
    Zero();
    QPixmap *returnRun(){return Run;}
    QPixmap *returnSSmash(){return SSmash;}
    QPixmap *returnMSmash(){return MSmash;}
    QPixmap *returnWSmash(){return WSmash;}
    QPixmap *returnDash(){return Dash;}
    QPoint *returnoffsetPointsDash(){return offsetPointsDash;}
    QPoint *returnoffsetPointsRun(){return offsetPointsRun;}
    QPoint *returnoffsetPointsSSmash(){return offsetPointsSSmash;}
    QPoint *returnoffsetPointsWSmash(){return offsetPointsWSmash;}
    QPoint *returnoffsetPointsMSmash(){return offsetPointsMSmash;}
    void writeRun(QPixmap *a){ memcpy(Run,a,100);}
    void writeDash(QPixmap *a){memcpy(Dash,a,100);}
    void writeSSmash(QPixmap *a){memcpy(SSmash,a,100);}
    void writeWSmash(QPixmap *a){memcpy(WSmash,a,100);}
    void writeMSmash(QPixmap *a){memcpy(MSmash,a,100);}
    void writePointsDash(QPoint *a){memcpy(offsetPointsDash,a,100);}
    void writePointsRun(QPoint *a){memcpy(offsetPointsRun,a,100);}
    void writePointsSSmash(QPoint *a){memcpy(offsetPointsSSmash,a,100);}
    void writePointsMSmash(QPoint *a){memcpy(offsetPointsMSmash,a,100);}
    void writePointsWSmash(QPoint *a){memcpy(offsetPointsWSmash,a,100);}


private:
    QPixmap *Run;
    QPixmap *SSmash;
    QPixmap *MSmash;
    QPixmap *WSmash;
    QPixmap *Dash;
    QPoint *offsetPointsDash;
    QPoint *offsetPointsSSmash;
    QPoint *offsetPointsRun;
    QPoint *offsetPointsWSmash;
    QPoint *offsetPointsMSmash;


};

#endif // ZERO_H
