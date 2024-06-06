#include "Formulario.h"
#include "ui_Formulario.h"
#include <QDebug>

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formulario)
{
    ui->setupUi(this);
    ui->instrumentoComboBox->addItem("Guitarra");
    ui->instrumentoComboBox->addItem("Viento");
    ui->instrumentoComboBox->addItem("Teclado");

    // Inicialmente solo mostramos los campos para Guitarra
    on_instrumentoComboBox_currentIndexChanged(0);
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::on_agregarButton_clicked()
{
    QString marca = ui->marcaLineEdit->text();
    double precio = ui->precioLineEdit->text().toDouble();
    int cantidadCuerdas = ui->cuerdasLineEdit->text().toInt();
    int cantidadTeclas = ui->teclasLineEdit->text().toInt();
    QString metalUsado = ui->metalLineEdit->text();

    Instrumento *instrumento = nullptr;
    if (ui->instrumentoComboBox->currentText() == "Guitarra") {
        instrumento = new Guitarra(marca, precio, cantidadCuerdas);
    } else if (ui->instrumentoComboBox->currentText() == "Viento") {
        instrumento = new Viento(marca, precio, metalUsado);
    } else if (ui->instrumentoComboBox->currentText() == "Teclado") {
        instrumento = new Teclado(marca, precio, cantidadTeclas);
    }

    if (instrumento) {
        instrumentos.append(instrumento);
        qDebug() << "Instrumento agregado: " << marca << ", " << precio;
        instrumento->afinar();
    }
}

void Formulario::on_verStockButton_clicked()
{
    for (Instrumento *instrumento : instrumentos) {
        qDebug() << instrumento->getDescripcion();
    }
}

void Formulario::on_instrumentoComboBox_currentIndexChanged(int index)
{
    ui->cuerdasLineEdit->setVisible(index == 0);  // Guitarra
    ui->teclasLineEdit->setVisible(index == 2);   // Teclado
    ui->metalLineEdit->setVisible(index == 1);    // Viento

    // Limpiar campos que no sean relevantes
    if (index != 0) ui->cuerdasLineEdit->clear();
    if (index != 2) ui->teclasLineEdit->clear();
    if (index != 1) ui->metalLineEdit->clear();
}
