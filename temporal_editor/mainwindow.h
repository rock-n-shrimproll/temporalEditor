#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include <QWidget>

#include "editwindow.h"
#include "viewwindow.h"
#include "db_operating.h"

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

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    EditWindow *editwindow;
    ViewWindow *viewwindow;
    QSqlDatabase temp_editor;
    QString selected_dictionary;

    int ExecuteSqlScriptFile(QSqlDatabase & db, const QString & fileName);
    QString set_dictionary(Ui::MainWindow *ui);

public slots:
    void gobackEdit_clicked();
    void gobackView_clicked();

signals:
    void set_db(QSqlDatabase temp_editor);
    void set_current_dict(QString cur_dict);

};
#endif // MAINWINDOW_H
