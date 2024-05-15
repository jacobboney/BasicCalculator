#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <GlobalProps/globalprops.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    
    qmlRegisterUncreatableType < GlobalProps > ( "GlobalPropsClass", 1, 0, "GlobalPropsClass", QStringLiteral("Do not create this class!") );
    GlobalProps globalProps;
    
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    
    QQmlContext* context(engine.rootContext());
    context->setContextProperty("GlobalProps", &globalProps);
    
    engine.loadFromModule("BasicCalculator", "Main");

    return app.exec();
}
