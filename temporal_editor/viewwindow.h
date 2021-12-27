#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class ViewWindow;
}

class ViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewWindow(QWidget *parent = nullptr);
    ~ViewWindow();
    QString current_dict;

private slots:
    void on_pushButtongoBack_clicked();

private:
    Ui::ViewWindow *ui;

    QSqlDatabase current_db;
    QSqlQuery *query;
    QSqlTableModel *viewmodel;

public slots:
    void get_db(QSqlDatabase);
    void get_current_dict(QString);

signals:
    void goback();
};

#endif // VIEWWINDOW_H
