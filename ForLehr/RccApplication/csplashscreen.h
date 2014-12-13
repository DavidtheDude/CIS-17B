#ifndef CSPLASHSCREEN_H
#define CSPLASHSCREEN_H

#include <QFrame>
#include <QPainter>

class CSplashScreen : public QFrame
{
    public:
     CSplashScreen(const QPixmap& pixmap);

     void clearMessage();
     void showMessage(const QString& theMessage, int theAlignment = Qt::AlignLeft, const QColor& theColor = Qt::black);

    private:
     virtual void paintEvent(QPaintEvent* pe);

     QPixmap itsPixmap;
     QString itsMessage;
     int itsAlignment;
     QColor itsColor;
};

#endif // CSPLASHSCREEN_H
