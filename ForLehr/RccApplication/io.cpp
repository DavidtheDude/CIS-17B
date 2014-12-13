#include "io.h"

#include <QtCore>

#include "settings.h"
#include "user.h"

IO::IO() {
    userFile = "users.ini";
}

/**
 * Saves a user to the local files
 * @brief IO::saveUser
 * @param email unhashed
 * @param pass needs to be sha1 hashed
 * @param role [Optional] the users role defaulted to regular user see User::Roles for full list
 * @author Michael
 */
void IO::saveUser( QString email, QString pass, QString role ){
    QByteArray emailHash = QCryptographicHash::hash( email.toUtf8(), QCryptographicHash::Sha1 );
    QString emailSha = emailHash.toHex();
    User user( email, pass, role );
    Settings settings( userFile );
    settings.loadSettings();
    if( settings.getSetting( email ) == "" ){
        settings.saveSetting( emailSha, user.getInsertString() );
    }
}

/**
 * @brief IO::checkUser
 * @param email
 * @param pass
 * @return true if correct credentails
 * @author Michael
 */
bool IO::checkUser( QString email, QString pass ){
    Settings settings( userFile );
    settings.loadSettings();
    if( settings.settingExists( email ) ) {
        User user( settings.getSetting( email ) );
        if( user.getPass() == pass ){
            return true;
        }
    }

    return false;
}
