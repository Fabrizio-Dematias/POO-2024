// linea.cpp
#include "linea.h"
#include <QPainter>

// Constructor
Linea::Linea(int xInicial, int yInicial, int xFinal, int yFinal, QWidget *parent)
    : QWidget(parent), x_inicial(xInicial), y_inicial(yInicial), x_final(xFinal), y_final(yFinal)
{
}

// Getters
int Linea::getXInicial() const
{
    return x_inicial;
}

int Linea::getYInicial() const
{
    return y_inicial;
}

int Linea::getXFinal() const
{
    return x_final;
}

int Linea::getYFinal() const
{
    return y_final;
}

// Setters
void Linea::setXInicial(int xInicial)
{
    x_inicial = xInicial;
    update(); // Llama a update() para redibujar el widget cuando cambian los valores
}

void Linea::setYInicial(int yInicial)
{
    y_inicial = yInicial;
    update();
}

void Linea::setXFinal(int xFinal)
{
    x_final = xFinal;
    update();
}

void Linea::setYFinal(int yFinal)
{
    y_final = yFinal;
    update();
}

// Método de dibujo
void Linea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Dibuja la línea usando los valores x_inicial, y_inicial, x_final, y_final
    painter.drawLine(x_inicial, y_inicial, x_final, y_final);
}
