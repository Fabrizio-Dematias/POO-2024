#ifndef MILABEL_H
#define MILABEL_H

#include <QLabel>
#include <QMouseEvent>

class MiLabel : public QLabel {
    Q_OBJECT

public:
    explicit MiLabel(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // MILABEL_H
