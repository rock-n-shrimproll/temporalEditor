#include "editwindow.h"
#include "ui_editwindow.h"
#include "mainwindow.h"



EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Окно редактора словаря");

//    query->exec("select * from temporality");

    ui->comboBoxDeclension->addItems({"что-то раз", "что-то два", "что-то три"});
    ui->comboBoxTemporality->addItems({"что-то раз", "что-то два", "что-то три"});
    
    //сетап картиночки знака вопроса
    question_mark.load("/Users/alexandradolidze/Desktop/Editor/temporal_editor/qm.png");
    QIcon question_icon(question_mark);

    // TODO: переделать в vector и foreach
    ui->pushButton_qmff->setIcon(question_icon);
    ui->pushButton_qmff->setIconSize(question_mark.rect().size());
    ui->pushButton_qmff->setFixedSize(question_mark.rect().size());
    ui->pushButton_qmff->setToolTip("сообщение о первой форме");

    ui->pushButton_qmqb->setIcon(question_icon);
    ui->pushButton_qmqb->setIconSize(question_mark.rect().size());
    ui->pushButton_qmqb->setFixedSize(question_mark.rect().size());
    ui->pushButton_qmqb->setToolTip("сообщение о квазиоснове");

    ui->pushButton_qmdt->setIcon(question_icon);
    ui->pushButton_qmdt->setIconSize(question_mark.rect().size());
    ui->pushButton_qmdt->setFixedSize(question_mark.rect().size());
    ui->pushButton_qmdt->setToolTip("сообщение о виде склонения");

    ui->pushButton_qmtemp->setIcon(question_icon);
    ui->pushButton_qmtemp->setIconSize(question_mark.rect().size());
    ui->pushButton_qmtemp->setFixedSize(question_mark.rect().size());
    ui->pushButton_qmtemp->setToolTip("сообщение о темпоральности");

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

void EditWindow::get_db(QSqlDatabase db)
{
    current_db = db;
//    if (current_db.open()) {
//        QMessageBox::information(this, "Connection", "Success");
//    }
//    else {
//        QMessageBox::information(this, "Connection", "Fail");
//    }
//      qDebug() << "Error" << current_db.lastError().text();
}

void EditWindow::get_current_dict(QString selected_dictionary)
{
    current_dict = selected_dictionary;
    ui->label_current_dictionary->setText(current_dict);
    if (selected_dictionary == "Наречия" or selected_dictionary == "Предлоги"){
        ui->label_quazibase->hide();
        ui->label_declension_type->hide();

        ui->pushButton_qmqb->hide();
        ui->pushButton_qmdt->hide();

        ui->lineEditQuasibase->hide();
        ui->comboBoxDeclension->hide();
    }
    else if (selected_dictionary == "Местоимения" or selected_dictionary == "Существительные") {
        ui->label_temporality->hide();
        ui->pushButton_qmtemp->hide();
        ui->comboBoxTemporality->hide();
    }
}

void EditWindow::on_pushButtonAddToDict_clicked()
{
//    query->prepare("insert into () ");
}

void EditWindow::on_pushButton_qmff_clicked()
{
    QMessageBox::information(this, "Пример заполнения словаря", " Пример заполнения словаря");

}
