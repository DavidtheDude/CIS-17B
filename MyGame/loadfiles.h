#ifndef LOADFILES_H
#define LOADFILES_H

#include <QFile>
#include <QPixmap>
#include <QtXml/QDomElement>
#include <QDebug>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>

#include "zero.h"

class LoadFiles
{
public:
    LoadFiles();
    ~LoadFiles();
    void load(QString);
    void getFilePaths();
    QPixmap *returniSprites(){return iSprites;}
    QPoint *returnoffsetPoints(){return offsetPoints;}
private:
    Zero zeroSprites;
    QPixmap *iSprites;
    QPoint *offsetPoints;
    int size;



};

#endif // LOADFILES_H
