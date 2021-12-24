#include "editwindow.h"
#include "ui_editwindow.h"
#include "mainwindow.h"



EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    ui->comboBoxDeclension->addItems({"что-то раз", "что-то два", "что-то три"});
    ui->comboBoxTemporality->addItems({"что-то раз", "что-то два", "что-то три"});
    
    question_mark.load("/Users/alexandradolidze/Desktop/Editor/temporal_editor/qm.png");
    // TODO: переделать в foreach
    ui->label_qmdt->setPixmap(question_mark);
    ui->label_qmff->setPixmap(question_mark);
    ui->label_qmqb->setPixmap(question_mark);
    ui->label_qmtemp->setPixmap(question_mark);

    ui->label_qmdt->setToolTip("сообщение о виде склонения"); //добавить в тултип ссылку на куда-то
    ui->label_qmff->setToolTip("сообщение о первой форме");
    ui->label_qmqb->setToolTip("сообщение о квазиоснове");
    ui->label_qmtemp->setToolTip("сообщение о темпоральности");

    in_firstform = ui->lineEditFirstform->text();
    in_quasibase = ui->lineEditQuasibase->text();
    in_temporality = ui->comboBoxTemporality->currentIndex();
    in_declencion = ui->comboBoxDeclension->currentIndex();

//    query->exec("select * from dictionary;");
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_pushButtongoBack_clicked()
{
    emit goback();
    this -> hide();
}

void EditWindow::get_current_dict(QString selected_dictionary)
{
    current_dict = selected_dictionary;
    ui->label_current_dictionary->setText(current_dict);
}

void EditWindow::get_db(QSqlDatabase db)
{
    current_db = db;
//    if (current_db.open()) {
//        QMessageBox::information(this, "Connection", "Success");
//    }
//    else {
//        QMessageBox::information(this, "Connection", "Fail");
//    }
}

