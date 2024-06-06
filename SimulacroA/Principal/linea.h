#ifndef LINEA_H
#define LINEA_H

#include <QWidget>

class Linea : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    explicit Linea(int xInicial = 0, int yInicial = 0, int xFinal = 0, int yFinal = 0, QWidget *parent = nullptr);

    // Getters
    int getXInicial() const;
    int getYInicial() const;
    int getXFinal() const;
    int getYFinal() const;

    // Setters
    void setXInicial(int xInicial);
    void setYInicial(int yInicial);
    void setXFinal(int xFinal);
    void setYFinal(int yFinal);

protected:
    // Método de dibujo
    void paintEvent(QPaintEvent *event) override;

private:
    int x_inicial;
    int y_inicial;
    int x_final;
    int y_final;
};

#endif // LINEA_H
