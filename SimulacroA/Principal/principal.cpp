#include "principal.h"
#include "ui_principal.h"
#include "linea.h"
#include <QPainter>

Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    // Conectar a la base de datos utilizando la instancia única de AdminDB
    AdminDB *adminDB = AdminDB::getInstance();
    if (adminDB->connectToDatabase("C:/Users/fabri/OneDrive/Escritorio/lineas.db")) {
        qDebug() << "Conexión exitosa a la base de datos.";
    } else {
        qDebug() << "Falló la conexión a la base de datos.";
    }

    // Ejecutar una consulta para obtener todas las líneas
    QSqlQuery query = adminDB->executeQuery("SELECT * FROM lineas");
    while (query.next()) {
        int xInicial = query.value("x_inicial").toInt();
        int yInicial = query.value("y_inicial").toInt();
        int xFinal = query.value("x_final").toInt();
        int yFinal = query.value("y_final").toInt();

        // Crear un nuevo objeto Linea con los datos leídos y agregarlo a la lista de líneas
        Linea *linea = new Linea(xInicial, yInicial, xFinal, yFinal, this);
        lineas.append(linea);
    }

    // Asegúrate de que haya al menos una línea para evitar errores
    if (lineas.isEmpty()) {
        qDebug() << "No se encontraron registros en la tabla 'lineas'.";
    }
}

Principal::~Principal()
{
    // Limpiar la lista de líneas
    qDeleteAll(lineas);
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    // Llamamos al paintEvent del QWidget para que se pinte correctamente
    QWidget::paintEvent(event);

    // Creamos un QPainter para dibujar
    QPainter painter(this);

    // Dibujamos todas las líneas almacenadas en la lista
    for (Linea *linea : lineas) {
        painter.drawLine(linea->getXInicial(), linea->getYInicial(), linea->getXFinal(), linea->getYFinal());
    }
}
