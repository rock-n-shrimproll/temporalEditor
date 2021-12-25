#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QSqlQuery>

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr);
    ~EditWindow();

private:
    Ui::EditWindow *ui;
    QPixmap question_mark;


    QString in_firstform;
    QString in_quasibase;
    int in_temporality;
    int in_declencion;

    QString current_dict;

    QSqlDatabase current_db;
    QSqlQuery *query;

private slots:
    void on_pushButtongoBack_clicked();       

    void on_pushButtonAddToDict_clicked();

    void on_pushButton_qmff_clicked();

public slots:
    void get_db(QSqlDatabase);
    void get_current_dict(QString);

signals:
    void goback();
};

#endif // EDITWINDOW_H
