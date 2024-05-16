#include "ventana.h"
#include <QVBoxLayout>
#include "boton.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    Boton *boton = new Boton(this);
    layout->addWidget(boton);
    boton->colorear(Boton::Azul);

    setLayout(layout);
}
