#include "settings.h"

#include <QtCore>
/*
 * How to use me
 *
 * Settings settings( app.applicationDirPath() + "/config.ini", true, ":/res/config/config.ini" );
    settings.loadSettings();
    qDebug() << settings.getSetting( "go" );
    settings.saveSetting( "go", "derp" );
    qDebug() << settings.getSetting( "go" );
*/
/**
 * to use settings follow this rough pattern
 * Settings settings( app.applicationDirPath() + "/config.ini", true, ":/res/config/config.ini" );
 * settings.loadSettings();
 *
 * @brief Settings::Settings
 * @param file (can not be in the resource folder)
 * @param useDefault ( if true will copy the config file from default location to new file)
 * @param defaultFile
 * @author Michael
 */
Settings::Settings( QString file, bool useDefault, QString defaultFile ) {
    filename = file;
    QFile configFile( filename );
    if( !configFile.exists() && useDefault ){
        if ( !QFile::copy( defaultFile, filename ) ) {
            qDebug() << "file exists shit broke";
        } else{
            //it coppied make it writable
            configFile.setPermissions( QFile::WriteOther );
        }

    }
    else if ( !configFile.exists() && !useDefault ){
        qDebug() << "No file to load, not loading fallback, creating";
        configFile.open( QFile::WriteOnly );
        configFile.setPermissions( QFile::WriteOther );
        configFile.close();
    }
    qSettings = new QSettings( filename, QSettings::IniFormat );
    isLoaded = false;
    configFile.close();
}

/**
 * @brief Settings::~Settings
 * @author Michael
 */
Settings::~Settings() {
    delete qSettings;
}

/**
 * load the settings and save them into a map
 * @brief Settings::loadSettings
 * @return isLoaded
 * @author Michael
 */
bool Settings::loadSettings(){
    QFile configFile( filename );
    if( configFile.exists() ){
        const QStringList childKeys = qSettings->childKeys();
        foreach( const QString &childKey, childKeys ){
            settings.insert( childKey, qSettings->value( childKey ).toString() );
        }
        isLoaded = true;
    }
    else {
        qDebug() << "couldn't find file.";
    }
    configFile.close();
    return isLoaded;
}

/**
 * get a value from the settings map
 * @brief Settings::getSetting
 * @param key
 * @return QString value
 * @author Michael
 */
QString Settings::getSetting( QString key ){
    if( !isLoaded ){
        loadSettings();
    }
    return settings.value( key, "" );
}

/**
 * change a setting and save it to the file
 * @brief Settings::saveSetting
 * @param key
 * @param value
 * @author Michael
 */
void Settings::saveSetting( QString key, QString value ){
    if( !isLoaded ){
        loadSettings();
    }
    settings.insert( key, value );
    qSettings->setValue( key, value );
    qSettings->sync();
    qDebug() << "save status:" << qSettings->status();
}

/**
 * Appends a new value to the old value delimiting with a pipe
 * @brief Settings::appendSetting
 * @param key
 * @param value
 * @param delimiter by default pipe character
 * @author Michael
 */
void Settings::appendSetting( QString key, QString value, QString delimiter ){
    if( !isLoaded ){
        loadSettings();
    }
    if( settings.contains( key ) ){
        QString oldValue = getSetting( key );
        value = oldValue + delimiter + value;
        settings.insert( key, value );
    }
    qSettings->setValue( key, value );
    qSettings->sync();
    qDebug() << "save status:" << qSettings->status();
}

/**
 * get the settings map
 * @brief Settings::getSettings
 * @return map of settings
 * @author Michael
 */
QMap<QString, QString> Settings::getSettings(){
    if( !isLoaded ){
        loadSettings();
    }
    return settings;
}

/**
 * a check if the settings loading
 * @brief Settings::getIsLoaded
 * @return true if loaded
 * @author Michael
 */
bool Settings::getIsLoaded() {
    return isLoaded;
}

/**
 * check if a setting exists
 * @brief Settings::settingExists
 * @param key
 * @return true if exists
 * @author Michael
 */
bool Settings::settingExists( QString key ){
    if( !isLoaded ){
        loadSettings();
    }
    if( settings.contains( key ) ){
        return true;
    } else {
        return false;
    }
}
