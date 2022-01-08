#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::ExecuteSqlScriptFile(QSqlDatabase &db, const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return  0;

    QTextStream in(&file);
    QString sql = in.readAll();
    QStringList sqlStatements = sql.split(';', QString::SkipEmptyParts);
    int successCount = 0;

    foreach(const QString& statement, sqlStatements)
    {
        if (statement.trimmed() != "")
        {
            QSqlQuery query(db);
            if (query.exec(statement))
                successCount++;
            else
                qDebug() << "Failed:" << statement << "\nReason:" << query.lastError();
        }
    }
    return successCount;
}


//int ExecuteSqlScriptFile(QSqlDatabase & db, const QString & fileName)
//{
//    QFile file(fileName);
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//        return  0;

//    QTextStream in(&file);
//    QString sql = in.readAll();
//    QStringList sqlStatements = sql.split(';', QString::SkipEmptyParts);
//    int successCount = 0;

//    foreach(const QString& statement, sqlStatements)
//    {
//        if (statement.trimmed() != "")
//        {
//            QSqlQuery query(db);
//            if (query.exec(statement))
//                successCount++;
//            else
//                qDebug() << "Failed:" << statement << "\nReason:" << query.lastError();
//        }
//    }
//    return successCount;
//}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Главное окно редактора словарей темпоральных лексем");

    //создание субокон просмотра и редактора
    editwindow = new EditWindow(this);
    viewwindow = new ViewWindow(this);

    //TODO: тут какая-то хуеверть надо переделать
    if (QFile::exists("/Users/alexandradolidze/Desktop/Editor/temporal_editor/te_editor.db")){
        temp_editor = QSqlDatabase::addDatabase("QSQLITE", "from_main");
        temp_editor.setDatabaseName("/Users/alexandradolidze/Desktop/Editor/temporal_editor/te_editor.db");
        temp_editor.open();
    }
    else {
        temp_editor = QSqlDatabase::addDatabase("QSQLITE", "from_main");
        temp_editor.setDatabaseName("/Users/alexandradolidze/Desktop/Editor/temporal_editor/te_editor.db");
        temp_editor.open();
        ExecuteSqlScriptFile(temp_editor, "/Users/alexandradolidze/Desktop/Editor/create_db.sql");
        ExecuteSqlScriptFile(temp_editor, "/Users/alexandradolidze/Desktop/Editor/fill_in_db.sql");
    }

    //коннект главного окна и субокон по сигналу кнопки "Назад"
    connect(editwindow, &EditWindow::goback, this,  &MainWindow::gobackEdit_clicked);
    connect(viewwindow, &ViewWindow::goback, this, &MainWindow::gobackView_clicked);

    connect(this, &MainWindow::set_current_dict, editwindow, &EditWindow::get_current_dict);
    connect(this, &MainWindow::set_current_dict, viewwindow, &ViewWindow::get_current_dict);
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::set_dictionary(Ui::MainWindow *ui)
{
    QString cur_dict;
    if (ui->radioButton_noun->isChecked())
    {
        cur_dict = "Существительные";
    }
    else if (ui->radioButton_adj->isChecked())
    {
        cur_dict = "Прилагательные";
    }
    else if (ui->radioButton_pronoun->isChecked())
    {
        cur_dict = "Местоимения";
    }
    else if (ui->radioButton_adv->isChecked())
    {
        cur_dict = "Наречия";
    }
    else if (ui->radioButton_prep->isChecked())
    {
        cur_dict = "Предлоги";
    }
    else {
        cur_dict = "";
    }
    return cur_dict;
}

//QString set_dictionary(Ui::MainWindow *ui){
//    QString cur_dict;
//    if (ui->radioButton_noun->isChecked())
//    {
//        cur_dict = "Существительные";
//    }
//    else if (ui->radioButton_adj->isChecked())
//    {
//        cur_dict = "Прилагательные";
//    }
//    else if (ui->radioButton_pronoun->isChecked())
//    {
//        cur_dict = "Местоимения";
//    }
//    else if (ui->radioButton_adv->isChecked())
//    {
//        cur_dict = "Наречия";
//    }
//    else if (ui->radioButton_prep->isChecked())
//    {
//        cur_dict = "Предлоги";
//    }
//    else {
//        cur_dict = "";
//    }
//    return cur_dict;
//}

void MainWindow::on_pushButton_clicked()
{
    if (temp_editor.open()) {
        QMessageBox::information(this, "Connection", "Success");
    }
    else {
        QMessageBox::information(this, "Connection", "Fail");
    }

}

void MainWindow::on_pushButton_edit_clicked()
{
    selected_dictionary = set_dictionary(ui);
    this->editwindow->current_dict = selected_dictionary;

    if (selected_dictionary == "") {
        QMessageBox::warning(NULL, "Connection", "Выберите словарь");
    }
    else {
        emit(set_current_dict(selected_dictionary));
        this -> hide();
        editwindow -> show();
    }
}

void MainWindow::on_pushButton_view_clicked()
{
    selected_dictionary = set_dictionary(ui);
    this->viewwindow->current_dict = selected_dictionary;

    if (selected_dictionary == "") {
        QMessageBox::warning(NULL, "Connection", "Выберите словарь");
    }
    else {
        emit(set_current_dict(selected_dictionary));
        this -> hide();
        viewwindow -> show();
    }
}

void MainWindow::gobackEdit_clicked()
{
    this -> show();
}

void MainWindow::gobackView_clicked()
{
    this -> show();
}


