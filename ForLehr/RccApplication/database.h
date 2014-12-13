#ifndef DATABASE_H
#define DATABASE_H

#include <QtCore>
#include <QtSql>

class Database {
public:
    Database();
    Database( QString, QString, QString, QString, QString driver = "QMYSQL" );

    QSqlDatabase getDb();

    void init( QString, QString, QString, QString, QString driver = "QMYSQL" );
    void close();

    bool connect();
    bool connectionOpen();
    bool testConnection();
    bool createTable( QString );
    //bool insertToTable( QString );

    QString connectionInfo();

    QString getHostname() const;
    void setHostname(const QString &value);
    QString getUser() const;
    void setUser(const QString &value);
    QString getPassword() const;
    void setPassword(const QString &value);
    QString getDbName() const;
    void setDbName(const QString &value);
private:
    QString hostname;
    QString user;
    QString password;
    QString dbName;
    QString driver;
    QSqlDatabase db;
};

#endif // DATABASE_H
