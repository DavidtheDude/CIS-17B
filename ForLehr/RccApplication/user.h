#ifndef USER_H
#define USER_H

#include <QtCore>
class User
{
public:
    enum Roles { USER = 0, MODERATOR = 1, PROFESSOR = 2, ADMIN = 3 };

    User( QString, QString, QString role = QString::number( USER ) );
    User( QString );

    void setEmail(const QString &value);
    void setPass(const QString &value);
    void setRole(const QString &value);
    void setInsertString(const QString &value);

    QString toString();
    QString getEmail() const;
    QString getPass() const;
    QString getRole() const;
    QString getInsertString() const;
private:
    QString email;
    QString pass;
    QString role;
    QString insertString;
};

#endif // USER_H
