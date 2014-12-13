#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtCore>

class Globals
{
public:
    Globals();

    static QString getSessionEmail();
    static QString getSessionEmailHash();
    static void setGlobals( QString, QString );
    static void setSessionEmail(const QString &value);
    static void setSessionEmailHash(const QString &value);
private:
    static QString sessionEmail;
    static QString sessionEmailHash;
};

#endif // GLOBALS_H
