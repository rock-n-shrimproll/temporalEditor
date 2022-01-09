#include "editwindow.h"
#include "ui_editwindow.h"
#include "mainwindow.h"

EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Окно редактора словаря");

    current_db = QSqlDatabase::addDatabase("QSQLITE", "from_edit");
    current_db.setDatabaseName("D:\\Documents\\temporal_editor\\te_editor.db");
    current_db.open();

    //сетап картиночки знака вопроса
    question_mark.load("D:\\Documents\\temporal_editor\\qm.png");
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

//    QFile previous_data("D:\\temporalEditor-main\\temporalEditor-main\\temporal_editor\\previous_data.sql");
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_pushButtongoBack_clicked()
{
    emit goback();
    ui->comboBoxTemporality->clear();
    this -> hide();
}

void EditWindow::get_db(QSqlDatabase db)
{
    current_db = db;
}

void EditWindow::get_current_dict(QString selected_dictionary)
{
    current_dict = selected_dictionary;
    ui->label_current_dictionary->setText(current_dict);
    ui->comboBoxDeclension->clear();
    ui->comboBoxTemporality->clear();
    //TODO: change if_else to case with strings for set up for particular dictionary
    if (current_dict == "Местоимения") {
        ui->label_quazibase->show();
        ui->label_declension_type->show();

        ui->pushButton_qmqb->show();
        ui->pushButton_qmdt->show();

        ui->lineEditQuasibase->show();

        ui->comboBoxDeclension->clear();
        ui->comboBoxDeclension->show();

        ui->label_temporality->hide();
        ui->pushButton_qmtemp->hide();
        ui->comboBoxTemporality->hide();

        query = new QSqlQuery(current_db);
        if (query->exec("select * from flex")) {
            while (query->next()) {
//                qDebug() << query->value(0).toString();
                ui->comboBoxDeclension->addItem(query->value(1).toString()+", \" -"+query->value(2).toString()+", -"+query->value(3).toString()+", -"+query->value(4).toString()+", ...\"");
            }
        }
    }
    else if (current_dict == "Существительные") {
        ui->label_quazibase->show();
        ui->label_declension_type->show();

        ui->pushButton_qmqb->show();
        ui->pushButton_qmdt->show();

        ui->lineEditQuasibase->show();

        ui->comboBoxDeclension->clear();
        ui->comboBoxDeclension->show();

        ui->label_temporality->hide();

        ui->pushButton_qmtemp->hide();

        ui->comboBoxTemporality->hide();

        query = new QSqlQuery(current_db);

        if (query->exec("select * from noun_flex")) {
            while (query->next()) {
                ui->comboBoxDeclension->addItem(query->value(1).toString()+", \" -"+query->value(2).toString()+", -"+query->value(3).toString()+", -"+query->value(4).toString()+", ...\"");
            }
        }
    }
    else if (current_dict == "Наречия" or current_dict == "Предлоги"){
        //TODO: переделать этот hot mess, позорище

        ui->label_quazibase->hide();
        ui->label_declension_type->hide();

        ui->pushButton_qmqb->hide();
        ui->pushButton_qmdt->hide();

        ui->lineEditQuasibase->hide();
        ui->comboBoxDeclension->hide();

        ui->label_temporality->show();

        ui->pushButton_qmtemp->show();

        query = new QSqlQuery(current_db);
        if (query->exec("select * from temporality")) {
            while (query->next()) {
                ui->comboBoxTemporality->addItem(query->value(1).toString()+", "+query->value(2).toString()+", "+query->value(3).toString());
            }
        }

        ui->comboBoxTemporality->show();
    }
    else {
        ui->label_temporality->show();

        ui->pushButton_qmtemp->show();

        query = new QSqlQuery(current_db);
        if (query->exec("select * from temporality")) {
            while (query->next()) {
                ui->comboBoxTemporality->addItem(query->value(1).toString()+", "+query->value(2).toString()+", "+query->value(3).toString());
            }
        }

        ui->comboBoxTemporality->show();
        ui->label_quazibase->show();
        ui->label_declension_type->show();

        ui->pushButton_qmqb->show();
        ui->pushButton_qmdt->show();

        ui->lineEditQuasibase->show();

        ui->comboBoxDeclension->clear();
        ui->comboBoxDeclension->show();

        if (query->exec("select * from flex")) {
            while (query->next()) {
                ui->comboBoxDeclension->addItem(query->value(1).toString()+", \" -"+query->value(2).toString()+", -"+query->value(3).toString()+", -"+query->value(4).toString()+", ...\"");
            }
        }
    }
}

void EditWindow::on_pushButtonAddToDict_clicked()
{
    if (current_dict == "Существительные"){
        QString base_Query = "insert into noun (firstform, quasibase, set_of_flexes) values (:ff, :qb, :flex);";
        query = new QSqlQuery(current_db);
        query->prepare(base_Query);

        in_firstform = ui->lineEditFirstform->text();
        in_quasibase = ui->lineEditQuasibase->text();
        in_declencion = ui->comboBoxDeclension->currentIndex();

        query->bindValue(":ff", in_firstform);
        query->bindValue(":qb", in_quasibase);
        query->bindValue(":flex", in_declencion+1);

        if (query->exec()) {
            QMessageBox::information(this, "Добавление", "Добавлено");
            ui->lineEditFirstform->clear();
            ui->lineEditQuasibase->clear();
        }
        else {
            qDebug() << "Всё сломалось" << query->lastError();
            QMessageBox::warning(this, "Добавление", "Неверно введены данные");
            ui->lineEditFirstform->clear();
            ui->lineEditQuasibase->clear();
        }
    }
    if (current_dict == "Местоимения")
    {
        QString base_Query = "insert into pronoun (firstform, quasibase, set_of_flexes) values (:ff, :qb, :flex);";
        query = new QSqlQuery(current_db);
        query->prepare(base_Query);

        in_firstform = ui->lineEditFirstform->text();
        in_quasibase = ui->lineEditQuasibase->text();
        in_declencion = ui->comboBoxDeclension->currentIndex();

        query->bindValue(":ff", in_firstform);
        query->bindValue(":qb", in_quasibase);
        query->bindValue(":flex", in_declencion+1);

        if (query->exec()) {
           QMessageBox::information(this, "Добавление", "Добавлено");
           ui->lineEditFirstform->clear();
           ui->lineEditQuasibase->clear();
        }
        else {
           qDebug() << "Всё сломалось" << query->lastError();
           QMessageBox::warning(this, "Добавление", "Неверно введены данные");
           ui->lineEditFirstform->clear();
           ui->lineEditQuasibase->clear();
        }
    }
    if (current_dict == "Прилагательные")
    {
        QString base_Query = "insert into adjective (firstform, quasibase, set_of_flexes, temporality) values (:ff, :qb, :flex, :temp);";
        query = new QSqlQuery(current_db);
        query->prepare(base_Query);

        in_firstform = ui->lineEditFirstform->text();
        in_quasibase = ui->lineEditQuasibase->text();
        in_declencion = ui->comboBoxDeclension->currentIndex();
        in_temporality = ui->comboBoxTemporality->currentIndex();

        query->bindValue(":ff", in_firstform);
        query->bindValue(":qb", in_quasibase);
        query->bindValue(":flex", in_declencion+1);
        query->bindValue(":temp", in_temporality+1);

        if (query->exec()) {
           QMessageBox::information(this, "Добавление", "Добавлено");
           ui->lineEditFirstform->clear();
           ui->lineEditQuasibase->clear();
        }
        else {
           qDebug() << "Всё сломалось" << query->lastError();
           QMessageBox::warning(this, "Добавление", "Неверно введены данные");
           ui->lineEditFirstform->clear();
           ui->lineEditQuasibase->clear();
        }
    }
    if (current_dict == "Предлоги")
    {
        QString base_Query = "insert into preposition (firstform, temporality) values (:ff, :temp);";
        query = new QSqlQuery(current_db);
        query->prepare(base_Query);

        in_firstform = ui->lineEditFirstform->text();
        in_temporality = ui->comboBoxTemporality->currentIndex();

        query->bindValue(":ff", in_firstform);
        query->bindValue(":temp", in_temporality+1);

        if (query->exec()) {
           QMessageBox::information(this, "Добавление", "Добавлено");
           ui->lineEditFirstform->clear();
           ui->lineEditQuasibase->clear();
        }
        else {
           qDebug() << "Всё сломалось" << query->lastError();
           QMessageBox::warning(this, "Добавление", "Неверно введены данные");
           ui->lineEditFirstform->clear();
           ui->lineEditQuasibase->clear();
        }
    }
    if (current_dict == "Наречия")
    {
        QString base_Query = "insert into adverb (firstform, temporality) values (:ff, :temp);";
        query = new QSqlQuery(current_db);
        query->prepare(base_Query);

        in_firstform = ui->lineEditFirstform->text();
        in_temporality = ui->comboBoxTemporality->currentIndex();

        query->bindValue(":ff", in_firstform);
        query->bindValue(":temp", in_temporality+1);

        if (query->exec()) {
           QMessageBox::information(this, "Добавление", "Добавлено");
           ui->lineEditFirstform->clear();
           ui->lineEditQuasibase->clear();
        }
        else {
           qDebug() << "Всё сломалось" << query->lastError();
           QMessageBox::warning(this, "Добавление", "Неверно введены данные");
           ui->lineEditFirstform->clear();
           ui->lineEditQuasibase->clear();
        }
    }
}

//void EditWindow::on_pushButton_qmff_clicked()
//{
//    QMessageBox message;
//    message.setIcon(QMessageBox::Information);
//    message.setText("Пример заполнения!");
//    message.setInformativeText("Текущая форма элемента темпоральной информации:\n Например, 'недельному' -- первая форма 'недельному'");
//    message.setDefaultButton(QMessageBox::Ok);
//}

//void EditWindow::on_pushButton_qmqb_clicked()
//{
//    QMessageBox message;
//    message.setIcon(QMessageBox::Information);
//    message.setText("Пример заполнения!");
//    message.setInformativeText("Квазиоснова элемента темпоральной информации:\n Например, 'недельному' -- квазиоснова 'недельн'");
//    message.setDefaultButton(QMessageBox::Ok);
//}

//void EditWindow::on_pushButton_qmdt_clicked()
//{
//    QMessageBox message;
//    message.setIcon(QMessageBox::Information);
//    message.setText("Пример заполнения!");
//    message.setInformativeText("Вид склонения элемента темпоральной информации:\n Например, 'недельному' -- Дательный падеж, 1а склонение");
//    message.setDefaultButton(QMessageBox::Ok);
//}

//void EditWindow::on_pushButton_qmtemp_clicked()
//{
//    QMessageBox message;
//    message.setIcon(QMessageBox::Information);
//    message.setText("Пример заполнения!");
//    message.setInformativeText("Класс темпоральности элемента темпоральной информации:\n Например, 'недельному' -- интервальное, длительное");
//    message.setDefaultButton(QMessageBox::Ok);
//}
