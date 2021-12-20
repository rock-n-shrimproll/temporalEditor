#include "clickable_label.h"

clickable_label::clickable_label(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

clickable_label::~clickable_label() {}

void clickable_label::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
