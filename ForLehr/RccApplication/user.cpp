#include "user.h"
/**
 * create a user the old school way
 * @brief User::User
 * @param email
 * @param pass
 * @param role the users role
 * @author Michael
 */
User::User( QString email, QString pass, QString role ) {
    this->email = email;
    this->pass = pass;
    this->role = role;
    this->insertString = email + "|" + pass + "|" + role;
}
/**
 * create a user with the insert string that is stored in the file
 * @brief User::User
 * @param insertString
 * @author Michael
 */
User::User( QString insertString ) {
    this->insertString = insertString;
    QStringList decode = insertString.split( "|" );
    this->email = decode.value( 0 );
    this->pass = decode.value( 1 );
    this->role = decode.value( 2 );
}

//generated getters and setters put user code above this --michael
QString User::toString(){
    return QString( "%1, %2, %3" ).arg( this->email, this->pass, this->role );
}

QString User::getEmail() const
{
    return email;
}

void User::setEmail(const QString &value)
{
    email = value;
}
QString User::getPass() const
{
    return pass;
}

void User::setPass(const QString &value)
{
    pass = value;
}
QString User::getRole() const
{
    return role;
}
QString User::getInsertString() const
{
    return insertString;
}

void User::setInsertString(const QString &value)
{
    insertString = value;
}

void User::setRole(const QString &value)
{
    role = value;
}


