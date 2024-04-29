#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void actualizarParametros();

private:
    QGroupBox *groupBox;
    QVBoxLayout *layout;
    QPushButton *btnActualizar;
    int diametroBola;
    int velocidad;
    QTimer *timer;
    int posX;
    int direccion;

    QPixmap bolaPixmap;

    void moverBola();
};

#endif // VENTANA_H
