#include "viewwindow.h"
#include "ui_viewwindow.h"

ViewWindow::ViewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewWindow)
{
    ui->setupUi(this);
}

ViewWindow::~ViewWindow()
{
    delete ui;
}


void ViewWindow::on_pushButtongoBack_clicked()
{
    emit goback();
    this -> hide();
}

void ViewWindow::get_current_dict(QString selected_dictionary)
{
    current_dict = selected_dictionary;
    ui->labelTitle->setText(current_dict);
}
