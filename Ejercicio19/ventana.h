#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>

class Ventana : public QWidget
{
    Q_OBJECT
public:
    explicit Ventana(QWidget *parent = nullptr);

signals:

protected slots:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    QImage canvas;
    QPoint lastPos;
    QColor currentColor;
    int penSize;

    void updatePenSize(int delta);
    void clearCanvas();
};

#endif // VENTANA_H
