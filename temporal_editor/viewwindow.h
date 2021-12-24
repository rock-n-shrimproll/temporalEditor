#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class ViewWindow;
}

class ViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewWindow(QWidget *parent = nullptr);
    ~ViewWindow();

private slots:
    void on_pushButtongoBack_clicked();

private:
    Ui::ViewWindow *ui;
    QString current_dict;

public slots:
//    void get_db(QSqlDatabase);
    void get_current_dict(QString);

signals:
    void goback();
};

#endif // VIEWWINDOW_H
