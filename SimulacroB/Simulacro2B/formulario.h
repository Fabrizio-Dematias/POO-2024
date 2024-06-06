#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QVector>
#include "Instrumento.h"
#include "Guitarra.h"
#include "Viento.h"
#include "Teclado.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Formulario; }
QT_END_NAMESPACE

class Formulario : public QWidget
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
    ~Formulario();

private slots:
    void on_agregarButton_clicked();
    void on_verStockButton_clicked();
    void on_instrumentoComboBox_currentIndexChanged(int index);

private:
    Ui::Formulario *ui;
    QVector<Instrumento*> instrumentos;
};

#endif // FORMULARIO_H
