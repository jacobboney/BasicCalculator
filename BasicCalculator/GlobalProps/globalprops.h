#ifndef GLOBALPROPS_H
#define GLOBALPROPS_H

#include <QObject>
#include <QSize>

class GlobalProps : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QSize mainWindow READ mainWindow WRITE setMainWindow NOTIFY mainWindowChanged FINAL)
    
public:
    explicit GlobalProps(QObject *parent = nullptr);
    
    QSize mainWindow() const;
    
public slots:
    void setMainWindow(const QSize &newMainWindow);    

signals:
    
    void mainWindowChanged();
    
private:
    
    QSize m_mainWindow;
};

#endif // GLOBALPROPS_H
