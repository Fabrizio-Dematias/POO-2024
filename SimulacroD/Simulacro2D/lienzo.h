#ifndef LIENZO_H
#define LIENZO_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QPainter>
#include <QVector>
#include <QPoint>
#include "MiLabel.h"

enum class GrosorTrazo {
    TrazoFino = 1,
    TrazoMediano = 3,
    TrazoGrueso = 5
};

class Lienzo : public QWidget {
    Q_OBJECT

public:
    explicit Lienzo(QWidget *parent = nullptr);
    void setGrosorTrazo(GrosorTrazo nuevoGrosor);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void borrarTodo();

private:
    bool dibujando;
    GrosorTrazo grosor;
    QVector<QPoint> puntos;
    MiLabel *label;

    void inicializarLabel();
};

#endif // LIENZO_H
