#include "editwindow.h"
#include "ui_editwindow.h"
#include "mainwindow.h"



EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    ui->comboBoxDeclension->addItems({"что-то раз", "что-то два", "что-то три"});
    
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

//    choosen_dictionary = mainwindow.choosen_dictionary;
//    switch (choosen_dictionary) {
//    case 1:
//        current_dictionary == "существительное"
//    case 2:
//        current_dictionary == "прилагательное"
//    case 3:
//        current_dictionary == "наречие"
//    case 4:
//        current_dictionary == "предлог"
//    }

    in_firstform = ui->lineEditFirstform->text();
    in_quasibase = ui->lineEditQuasibase->text();
    in_temporality = ui->spinBoxTemporality->value();
    in_declencion = ui->comboBoxDeclension->currentIndex();

    //подключение к бд -- на весь проект
    //query = new QSqlQuery(temp_editor);

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

//EditWindow::get_current_dictionary()
//{
//    ui->label_current_dict->setText();
//}

//void EditWindow::show_current_dictionary_in_label()
//{
//    this->choosen_dict->setText(current_dictionary);
//}
