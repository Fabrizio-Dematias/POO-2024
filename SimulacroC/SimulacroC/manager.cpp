#include "manager.h"
#include "login.h"

Manager* Manager::m_instance = nullptr;

Manager* Manager::instance()
{
    if (!m_instance)
        m_instance = new Manager();
    return m_instance;
}

Manager::Manager(QObject *parent) : QObject(parent)
{
}

void Manager::showLogin()
{
    if (m_currentWidget)
        m_currentWidget->close();

    m_currentWidget = new Login();
    m_currentWidget->show();
}
