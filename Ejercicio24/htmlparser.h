#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <QObject>
#include <QStringList>

class HtmlParser : public QObject
{
    Q_OBJECT
public:
    explicit HtmlParser(QObject *parent = nullptr);

    // Método para analizar el HTML y extraer las URLs de los recursos
    QStringList parseHtml(const QString &html);

signals:

};

#endif // HTMLPARSER_H
