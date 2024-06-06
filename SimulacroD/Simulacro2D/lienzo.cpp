#include "Lienzo.h"

Lienzo::Lienzo(QWidget *parent) : QWidget(parent), dibujando(false), grosor(GrosorTrazo::TrazoFino) {
    setMouseTracking(true);
    inicializarLabel();
}

void Lienzo::setGrosorTrazo(GrosorTrazo nuevoGrosor) {
    grosor = nuevoGrosor;
}

void Lienzo::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen(Qt::black, static_cast<int>(grosor), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

    for (const QPoint &punto : puntos) {
        painter.drawPoint(punto);
    }
}

void Lienzo::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
        dibujando = true;
    } else if (event->key() == Qt::Key_D) {
        dibujando = false;
    } else if (event->key() == Qt::Key_Plus || event->key() == Qt::Key_Equal) {
        // Aumentar grosor del trazo
        if (grosor == GrosorTrazo::TrazoFino) {
            setGrosorTrazo(GrosorTrazo::TrazoMediano);
        } else if (grosor == GrosorTrazo::TrazoMediano) {
            setGrosorTrazo(GrosorTrazo::TrazoGrueso);
        }
    } else if (event->key() == Qt::Key_Minus) {
        // Disminuir grosor del trazo
        if (grosor == GrosorTrazo::TrazoGrueso) {
            setGrosorTrazo(GrosorTrazo::TrazoMediano);
        } else if (grosor == GrosorTrazo::TrazoMediano) {
            setGrosorTrazo(GrosorTrazo::TrazoFino);
        }
    }
}

void Lienzo::mouseMoveEvent(QMouseEvent *event) {
    if (dibujando) {
        puntos.append(event->pos());
        update();
    }
}

void Lienzo::borrarTodo() {
    puntos.clear();
    update();
}

void Lienzo::inicializarLabel() {
    label = new MiLabel(this);
    label->setText("Clear");
    label->move(width() - 50, height() - 30);
    connect(label, &MiLabel::clicked, this, &Lienzo::borrarTodo);
}
