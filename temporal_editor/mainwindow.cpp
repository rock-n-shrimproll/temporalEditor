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

    //коннект главного окна и субокон по сигналу кнопки "Назад"
    connect(editwindow, &EditWindow::goback, this,  &MainWindow::gobackEdit_clicked);
    connect(viewwindow, &ViewWindow::goback, this, &MainWindow::gobackView_clicked);
    
//    connect(this, &MainWindow::set_current_dictionary, editwindow, &EditWindow::get_current_dictionary);


    //checkboxes -- dictionaries
    // 1 -- noun
    // 2 -- adj
    // 3 -- adv
    // 4 -- prep
//    if (ui->radioButton_noun->isChecked())
//    {
//        choosen_dictionary = 1;
//        //editwindow->current_dictionary->setText("существительное");
//    }
//    if (ui->radioButton_adj->isChecked())
//    {
//        choosen_dictionary = 2;
//    }
//    if (ui->radioButton_adv->isChecked())
//    {
//        choosen_dictionary = 3;
//    }
//    if (ui->radioButton_prep->isChecked())
//    {
//        choosen_dictionary = 4;
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //access to db
    // set_db и get_db
    temp_editor = QSqlDatabase::addDatabase("QSQLITE");
    temp_editor.setHostName("localhost");
    temp_editor.setUserName("root");
    temp_editor.setPassword("root");
    temp_editor.setDatabaseName("./temporal_editor_db.db");
    bool ok = temp_editor.open();
    if (ok)
    {
        QMessageBox::information(this, "Connection", "DB connected");
    }
    else
    {
        QMessageBox::information(this, "Connection", "DB failed to connect");
    }
    query = new QSqlQuery(temp_editor);
    query -> exec("drop table if exists dictionary;");
}

void MainWindow::on_pushButton_view_clicked()
{
    this -> hide();
    viewwindow -> show();
}

void MainWindow::on_pushButton_edit_clicked()
{
//    emit(show_current_dictionary());
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


