#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //создание субокон просмотра и редактора
    editwindow = new EditWindow(this);
    viewwindow = new ViewWindow(this);

    //подключение к БД
    temp_editor = QSqlDatabase::addDatabase("QSQLITE");
    temp_editor.setDatabaseName("/Users/alexandradolidze/Desktop/Editor/temporal_editor/temporal_editor_db.db");

    connect(this, &MainWindow::set_db, editwindow, &EditWindow::get_db);
    emit(set_db(temp_editor));

    //коннект главного окна и субокон по сигналу кнопки "Назад"
    connect(editwindow, &EditWindow::goback, this,  &MainWindow::gobackEdit_clicked);
    connect(viewwindow, &ViewWindow::goback, this, &MainWindow::gobackView_clicked);

    connect(this, &MainWindow::set_current_dict, editwindow, &EditWindow::get_current_dict);
    connect(this, &MainWindow::set_current_dict, viewwindow, &ViewWindow::get_current_dict);
    
    //checkboxes -- dictionaries
    // 1 -- noun
    // 2 -- adj
    // 3 -- adv
    // 4 -- prep

//        if (ui->radioButton_noun->isChecked())
//        {
//            selected_dictionary = "Существительное";
//        }
//        if (ui->radioButton_adj->isChecked())
//        {
//            selected_dictionary = "Прилагательное";
//        }
//        if (ui->radioButton_adv->isChecked())
//        {
//            selected_dictionary = "Наречие";
//        }
//        if (ui->radioButton_prep->isChecked())
//        {
//            selected_dictionary = "Предлог";
//        }

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString set_dictionary(Ui::MainWindow *ui){
    QString cur_dict;
    if (ui->radioButton_noun->isChecked())
    {
        cur_dict = "Существительные";
    }
    if (ui->radioButton_adj->isChecked())
    {
        cur_dict = "Прилагательные";
    }
    if (ui->radioButton_pronoun->isChecked())
    {
        cur_dict = "Местоимения";
    }
    if (ui->radioButton_adv->isChecked())
    {
        cur_dict = "Наречия";
    }
    if (ui->radioButton_prep->isChecked())
    {
        cur_dict = "Предлоги";
    }
    return cur_dict;
}

void MainWindow::on_pushButton_clicked()
{
    if (temp_editor.open()) {
        QMessageBox::information(this, "Connection", "Success");
    }
    else {
        QMessageBox::information(this, "Connection", "Fail");
    }

}

void MainWindow::on_pushButton_view_clicked()
{

    selected_dictionary = set_dictionary(ui);
    emit(set_current_dict(selected_dictionary));

    this -> hide();
    viewwindow -> show();
}

void MainWindow::on_pushButton_edit_clicked()
{
    selected_dictionary = set_dictionary(ui);
    emit(set_current_dict(selected_dictionary));

    this -> hide();
    editwindow -> show();
}


void MainWindow::gobackEdit_clicked()
{
    this -> show();
}

void MainWindow::gobackView_clicked()
{
    this -> show();
}


