#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QPushButton>

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);

private slots:
    void onVolverButtonClicked();

private:
    QPushButton *volverButton;
};

#endif // VENTANA_H
