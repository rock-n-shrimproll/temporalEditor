#include "viewwindow.h"
#include "ui_viewwindow.h"

ViewWindow::ViewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Окно просмотра словаря");

//    query->exec("select * from flex");

//    if (query) {

//    }
//    else {

//    }

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

void ViewWindow::get_db(QSqlDatabase db)
{
    current_db = db;
//    if (current_db.open()) {
//        QMessageBox::information(this, "Connection", "Success");
//    }
//    else {
//        QMessageBox::information(this, "Connection", "Fail");
//    }
//    qDebug() << "Error" << current_db.lastError().text();
}

void ViewWindow::get_current_dict(QString selected_dictionary)
{
    current_dict = selected_dictionary;
    ui->labelTitle->setText(current_dict);
}
