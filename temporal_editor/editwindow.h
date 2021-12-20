#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QString>


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
//    QLabel *choosen_dict;
    QPixmap question_mark;

    QString in_firstform;
    QString in_quasibase;
    int in_temporality;
    int in_declencion;

//    int choosen_dictionary;

private slots:
    void on_pushButtongoBack_clicked();       

//public slots:
//    void get_current_dictionary();

signals:
    void goback();
};

#endif // EDITWINDOW_H
