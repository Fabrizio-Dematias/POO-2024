#include "boton.h"
#include <QPainter>

Boton::Boton(QWidget *parent) : QWidget(parent), currentColor(Qt::white) {
    setFixedSize(100, 50); // Tamaño fijo del botón
}

void Boton::colorear(Color color) {
    switch(color) {
    case Rojo:
        currentColor = Qt::red;
        break;
    case Verde:
        currentColor = Qt::green;
        break;
    case Azul:
        currentColor = Qt::blue;
        break;
    }
    update(); // Llama a repaint para redibujar el botón
}

void Boton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), currentColor);
}
