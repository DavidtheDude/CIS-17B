#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore>

class Settings {
public:
    Settings( QString file, bool useDefault = false, QString defaultFile = "" );
    ~Settings();

    bool loadSettings();
    void saveSetting( QString, QString );
    void appendSetting( QString, QString, QString delimiter = "|" );

    QString getSetting( QString );

    QMap<QString, QString> getSettings();

    bool getIsLoaded();
    bool settingExists( QString );

private:
    QSettings *qSettings;
    QMap<QString, QString> settings;
    QString filename;
    bool isLoaded;
};

#endif // SETTINGS_H
