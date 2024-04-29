#include "ventana.h"

Ventana::Ventana(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800, 600);
    canvas = QImage(size(), QImage::Format_RGB32);
    canvas.fill(Qt::white);
    currentColor = Qt::black;
    penSize = 1;

    setFocusPolicy(Qt::StrongFocus);
}

void Ventana::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, canvas);
}

void Ventana::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPos = event->pos();
    }
}

void Ventana::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPainter painter(&canvas);
        painter.setPen(QPen(currentColor, penSize, Qt::SolidLine, Qt::RoundCap));
        painter.drawLine(lastPos, event->pos());
        lastPos = event->pos();
        update();
    }
}

void Ventana::wheelEvent(QWheelEvent *event)
{
    int delta = event->angleDelta().y();
    updatePenSize(delta);
}

void Ventana::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_R:
        currentColor = Qt::red;
        break;
    case Qt::Key_G:
        currentColor = Qt::green;
        break;
    case Qt::Key_B:
        currentColor = Qt::blue;
        break;
    case Qt::Key_Escape:
        clearCanvas();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void Ventana::updatePenSize(int delta)
{
    if (delta > 0)
        penSize++;
    else
        penSize = qMax(1, penSize - 1);
}

void Ventana::clearCanvas()
{
    canvas.fill(Qt::white);
    update();
}


