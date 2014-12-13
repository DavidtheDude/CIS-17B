#ifndef MAIN_H
#define MAIN_H

#include <QtCore>

class Main {
public:
    explicit Main();
    static void setSessionEmail( QString );
    static QString getSessionEmail();

private:
    static QString sessionEmail;

};

#endif // MAIN_H
