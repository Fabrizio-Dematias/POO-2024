#ifndef BOTON_H
#define BOTON_H

#include <QWidget>

class Boton : public QWidget {
    Q_OBJECT

public:
    enum Color { Rojo, Verde, Azul };
    Boton(QWidget *parent = nullptr);

    void colorear(Color color);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QColor currentColor;
};

#endif // BOTON_H
