#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editwindow.h"
#include "viewwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_edit_clicked();

    void on_pushButton_view_clicked();

private:
    Ui::MainWindow *ui;
    EditWindow *editwindow;
    ViewWindow *viewwindow;

};
#endif // MAINWINDOW_H
