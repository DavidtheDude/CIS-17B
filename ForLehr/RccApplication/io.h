#ifndef IO_H
#define IO_H

#include <QtCore>
#include "user.h"

class IO
{
public:
    IO();

    void saveUser( QString, QString, QString role = QString::number( User::USER ) );

    bool checkUser( QString, QString );
private:
    QString userFile;
};

#endif // IO_H
