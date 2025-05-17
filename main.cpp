#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QFileInfo>
#include <QStandardPaths>
#include <QDir>
#include "QProcess"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
