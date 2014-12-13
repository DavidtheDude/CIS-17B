#include "globals.h"

QString Globals::sessionEmail = "";
QString Globals::sessionEmailHash = "";

/**
 * globals for the program
 * @brief Globals::Globals
 */
Globals::Globals() {
    Globals::sessionEmail = "";
    Globals::sessionEmailHash = "";
}

/**
 * get the email of the logged in user "" if not logged in
 * @brief Globals::getSessionEmail
 * @return
 */
QString Globals::getSessionEmail() {
    return Globals::sessionEmail;
}

/**
 * set the email of the logged in user
 * @brief Globals::setSessionEmail
 * @param value
 */
void Globals::setSessionEmail(const QString &value) {
    Globals::sessionEmail = value;
}

/**
 * get the emailhash of the logged in user "" if not logged in
 * @brief Globals::getSessionEmailHash
 * @return
 */
QString Globals::getSessionEmailHash()
{
    return Globals::sessionEmailHash;
}

/**
 * set the emailhash of the logged in user
 * @brief Globals::setSessionEmail
 * @param value
 */
void Globals::setSessionEmailHash(const QString &value)
{
    Globals::sessionEmailHash = value;
}

/**
 * set the emailhash && email of the logged in user
 * @brief Globals::setGlobals
 * @param email
 * @param hash
 */
void Globals::setGlobals( QString email, QString hash ){
    Globals::sessionEmail = email;
    Globals::sessionEmailHash = hash;
}


