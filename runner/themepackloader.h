#ifndef THEMEPACKLOADER_H
#define THEMEPACKLOADER_H

#include <QObject>
#include <QSettings>

class ThemepackLoader : public QSettings
{
    Q_OBJECT
    Q_PROPERTY(QString themeName READ QString WRITE setThemeName)

public:
    explicit ThemepackLoader(const QString &themeName,
            Format format =  QSettings::IniFormat,
            QObject *parent = 0);

    void setThemeName(const QString &name);

    QString wallpaper();
    QStringList widgets(const QString &type);
    QStringList qmlFilesFromTheme(const QString &themeName);

signals:
    void ready();

public slots:

private:
    void scanThemepackPrefix();

    class ThemepackLoaderPrivate;
    ThemepackLoaderPrivate *const d;
};

#endif // THEMEPACKLOADER_H