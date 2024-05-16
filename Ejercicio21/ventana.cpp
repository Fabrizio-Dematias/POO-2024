#include "ventana.h"
#include <QVBoxLayout>
#include "login.h"

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    volverButton = new QPushButton("Volver", this);
    layout->addWidget(volverButton);

    connect(volverButton, &QPushButton::clicked, this, &Ventana::onVolverButtonClicked);
}

void Ventana::onVolverButtonClicked() {
    Login *login = new Login();
    login->show();
    this->close();
}
