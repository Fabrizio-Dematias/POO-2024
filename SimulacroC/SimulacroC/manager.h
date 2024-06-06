#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QWidget>
#include <QPointer>

class Manager : public QObject
{
    Q_OBJECT

public:
    static Manager* instance();
    void showLogin();

private:
    explicit Manager(QObject *parent = nullptr);
    static Manager* m_instance;
    QPointer<QWidget> m_currentWidget;
};

#endif // MANAGER_H
