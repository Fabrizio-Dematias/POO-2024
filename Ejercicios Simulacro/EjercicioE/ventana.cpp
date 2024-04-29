#include "ventana.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent),
    diametroBola(50), // Valores predeterminados
    velocidad(1000),  // Valores predeterminados
    posX(0),          // Posición inicial de la bola
    direccion(1)      // Dirección inicial de la bola (1: derecha, -1: izquierda)
{
    groupBox = new QGroupBox("Parámetros de la Bola");
    layout = new QVBoxLayout;
    groupBox->setLayout(layout);

    btnActualizar = new QPushButton("Actualizar Parámetros");
    layout->addWidget(btnActualizar);

    connect(btnActualizar, &QPushButton::clicked, this, &Ventana::actualizarParametros);

    setLayout(layout);

    // Cargar la imagen de la bola desde el disco
    bolaPixmap.load("bola.png");

    // Inicializar el temporizador para mover la bola
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ventana::moverBola);
    timer->start(20); // Intervalo de tiempo en milisegundos
}

Ventana::~Ventana()
{
    delete groupBox;
    delete layout;
    delete btnActualizar;
    delete timer;
}

void Ventana::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(posX, height() / 2 - diametroBola / 2, diametroBola, diametroBola, bolaPixmap);
}

void Ventana::actualizarParametros()
{
    // Aquí puedes agregar la lógica para actualizar los parámetros
    // diametroBola y velocidad según los valores ingresados por el usuario
}

void Ventana::moverBola()
{
    // Actualizar la posición de la bola
    posX += direccion;

    // Cambiar la dirección si la bola llega a los bordes de la ventana
    if (posX <= 0 || posX >= width() - diametroBola)
    {
        direccion *= -1;
    }

    // Redibujar la ventana
    update();
}
