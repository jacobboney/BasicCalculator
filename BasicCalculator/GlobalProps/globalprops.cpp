#include "globalprops.h"

GlobalProps::GlobalProps(QObject *parent)
    : QObject{parent}
{}

QSize GlobalProps::mainWindow() const { return m_mainWindow; }

void GlobalProps::setMainWindow(const QSize &newMainWindow)
{
    if (m_mainWindow == newMainWindow)
        return;
    m_mainWindow = newMainWindow;
    emit mainWindowChanged();
}
