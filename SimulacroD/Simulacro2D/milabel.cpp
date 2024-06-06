#include "MiLabel.h"

MiLabel::MiLabel(QWidget *parent) : QLabel(parent) {}

void MiLabel::mousePressEvent(QMouseEvent *event) {
    emit clicked();
}
