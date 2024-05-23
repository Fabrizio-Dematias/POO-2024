#include "htmlparser.h"
#include <QRegularExpression>

HtmlParser::HtmlParser(QObject *parent) : QObject(parent)
{

}

QStringList HtmlParser::parseHtml(const QString &html)
{
    QStringList urls;

    // Expresiones regulares para encontrar las URLs de los recursos
    QRegularExpression imgRegex("<img\\s+[^>]*src=\"([^\"]*)\"");
    QRegularExpression cssRegex("<link\\s+[^>]*href=\"([^\"]*)\"");
    QRegularExpression jsRegex("<script\\s+[^>]*src=\"([^\"]*)\"");

    // Coincidencias para imágenes
    QRegularExpressionMatchIterator imgMatches = imgRegex.globalMatch(html);
    while (imgMatches.hasNext()) {
        QRegularExpressionMatch match = imgMatches.next();
        urls.append(match.captured(1));
    }

    // Coincidencias para CSS
    QRegularExpressionMatchIterator cssMatches = cssRegex.globalMatch(html);
    while (cssMatches.hasNext()) {
        QRegularExpressionMatch match = cssMatches.next();
        urls.append(match.captured(1));
    }

    // Coincidencias para JavaScript
    QRegularExpressionMatchIterator jsMatches = jsRegex.globalMatch(html);
    while (jsMatches.hasNext()) {
        QRegularExpressionMatch match = jsMatches.next();
        urls.append(match.captured(1));
    }

    return urls;
}
