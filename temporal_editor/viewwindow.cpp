#include "viewwindow.h"
#include "ui_viewwindow.h"

ViewWindow::ViewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Окно просмотра словаря");
    ui->pushButton_save_csv->hide();

    current_db = QSqlDatabase::addDatabase("QSQLITE", "from view");
    current_db.setDatabaseName("/Users/alexandradolidze/Desktop/Editor/temporal_editor/te_editor.db");
    current_db.open();
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
}

void ViewWindow::get_current_dict(QString selected_dictionary)
{
    current_dict = selected_dictionary;
    ui->label->setText(current_dict);
    ui->labelTitle->setText(current_dict);

    viewmodel = new QSqlTableModel(this, current_db);

    //TODO: change if else to switch case
    if (current_dict == "Наречия"){
        viewmodel->setTable("adverb");
        viewmodel->setHeaderData(1,Qt::Horizontal,"Форма");
        viewmodel->setHeaderData(2,Qt::Horizontal,"Класс темпоральности");
    }
    else if (current_dict == "Местоимения") {
        viewmodel->setTable("pronoun");
        viewmodel->setHeaderData(1,Qt::Horizontal,"Форма");
        viewmodel->setHeaderData(2,Qt::Horizontal,"Квазиоснова");
        viewmodel->setHeaderData(3,Qt::Horizontal,"Квазифлексии");
    }
    else if (current_dict == "Существительные") {
        viewmodel->setTable("noun");
        viewmodel->setHeaderData(1,Qt::Horizontal,"Форма");
        viewmodel->setHeaderData(2,Qt::Horizontal,"Квазиоснова");
        viewmodel->setHeaderData(3,Qt::Horizontal,"Квазифлексии");
    }
    else if (current_dict == "Прилагательные") {
        viewmodel->setTable("adjective");
        viewmodel->setHeaderData(1,Qt::Horizontal,"Форма");
        viewmodel->setHeaderData(2,Qt::Horizontal,"Квазиоснова");
        viewmodel->setHeaderData(3,Qt::Horizontal,"Квазифлексии");
        viewmodel->setHeaderData(4,Qt::Horizontal,"Класс темпоральности");
    }
    else if (current_dict == "Предлоги") {
        viewmodel->setTable("preposition");
        viewmodel->setHeaderData(1,Qt::Horizontal,"Форма");
        viewmodel->setHeaderData(2,Qt::Horizontal,"Класс темпоральности");
    }

    viewmodel->select();
    ui->tableView->setModel(viewmodel);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->show();

}

