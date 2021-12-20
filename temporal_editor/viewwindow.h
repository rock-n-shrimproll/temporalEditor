#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QDialog>

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

signals:
    void goback();
};

#endif // VIEWWINDOW_H
