#include "database.h"

#include <QT>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QtSql>


Database::Database() {
    //init( "209.129.8.5", "48597", "48597", "48597csc17b" );
    init( "localhost", "48597", "root", "" );
}

Database::Database( QString host, QString dbName, QString user, QString pass, QString driver){
    init( host, dbName, user, pass, driver );
}

/**
 * sets all the values also basically a bug fix
 * @brief Database::init
 * @param host
 * @param dbName
 * @param user
 * @param pass
 */
void Database::init( QString host, QString dbName, QString user, QString pass, QString driver){
    this->hostname = host;
    this->dbName = dbName;
    this->user = user;
    this->password = pass;
    this->driver = driver;
}

/**
 * Get a database object so you can open it yourself
 * @brief Database::getDb
 * @return databse
 */
QSqlDatabase Database::getDb(){
    QSqlDatabase db1 = QSqlDatabase::addDatabase( driver ); //QMYSQL" );
    db1.setHostName( getHostname() );
    db1.setDatabaseName( getDbName() );
    db1.setUserName( getUser() );
    db1.setPassword( getPassword() );
    return db1;
}


/**
 * try to connect to the database
 * @brief Database::connect
 * @return false if failed
 */
bool Database::connect(){
    close();
    db = QSqlDatabase::addDatabase( driver );
    db.setHostName( getHostname() );
    db.setDatabaseName( getDbName() );
    db.setUserName( getUser() );
    db.setPassword( getPassword() );
    bool open = db.open();
    if( !open ){
        qDebug() << "Failed to connect: " << db.lastError();
    }
    return open;
}

/**
 * close the connection
 * @brief Database::close
 */
void Database::close(){
    if( db.isOpen() ){
        db.close();
    }
}

/**
 * checks if the database is connected
 * @brief Database::connectionOpen
 * @return true if a connection is open
 */
bool Database::connectionOpen(){
    return db.isOpen();
}

/**
 * @brief Database::createTable
 * @param statement
 * @return
 */
bool Database::createTable( QString statement ){
    bool pass = false;
    if( !connectionOpen() ) {
        qDebug() << "No connection";
        return pass;
    }
    if( statement.contains( "create table", Qt::CaseInsensitive ) ){
        QSqlQuery query = db.exec( statement );
        if( query.next() ) {
            qDebug() << query.value(0);
        }
        //qDebug() << "query failed: " << query.lastError();
    }
    return pass;
}

/**
 * @brief Database::testConnection
 * @return
 */
bool Database::testConnection(){
    bool result = false;
    if( connectionOpen() ){
        result = true;
    }
    else{
        result = connect();
        close();
    }
    return result;
}

/**
 * for debuging
 * @deprecated
 * @brief Database::connectionInfo
 * @return
 */
QString Database::connectionInfo(){
    QString str = "";
    str += getHostname() + ", " + getDbName() + ", "
        + getUser() + ", "
        + getPassword();
    return str;
}


//getters setter;

QString Database::getHostname() const
{
    return hostname;
}

void Database::setHostname(const QString &value)
{
    hostname = value;
}
QString Database::getUser() const
{
    return user;
}

void Database::setUser(const QString &value)
{
    user = value;
}
QString Database::getPassword() const
{
    return password;
}

void Database::setPassword(const QString &value)
{
    password = value;
}
QString Database::getDbName() const
{
    return dbName;
}

void Database::setDbName(const QString &value)
{
    dbName = value;
}
