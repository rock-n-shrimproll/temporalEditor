#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_edit_clicked()
{
    hide();
    editwindow = new EditWindow(this);
    editwindow -> show();
}

void MainWindow::on_pushButton_view_clicked()
{
    hide();
    viewwindow = new ViewWindow(this);
    viewwindow -> show();
}
