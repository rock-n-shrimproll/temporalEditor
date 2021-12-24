/********************************************************************************
** Form generated from reading UI file 'viewwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWWINDOW_H
#define UI_VIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewWindow
{
public:
    QPushButton *pushButtongoBack;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelTitle;
    QLabel *label_current_dictionary;
    QTableView *tableView;

    void setupUi(QDialog *ViewWindow)
    {
        if (ViewWindow->objectName().isEmpty())
            ViewWindow->setObjectName(QString::fromUtf8("ViewWindow"));
        ViewWindow->resize(464, 371);
        pushButtongoBack = new QPushButton(ViewWindow);
        pushButtongoBack->setObjectName(QString::fromUtf8("pushButtongoBack"));
        pushButtongoBack->setGeometry(QRect(10, 10, 81, 31));
        gridLayoutWidget = new QWidget(ViewWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 60, 371, 261));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(gridLayoutWidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        label_current_dictionary = new QLabel(gridLayoutWidget);
        label_current_dictionary->setObjectName(QString::fromUtf8("label_current_dictionary"));

        gridLayout->addWidget(label_current_dictionary, 0, 2, 1, 1);

        tableView = new QTableView(gridLayoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);


        retranslateUi(ViewWindow);

        QMetaObject::connectSlotsByName(ViewWindow);
    } // setupUi

    void retranslateUi(QDialog *ViewWindow)
    {
        ViewWindow->setWindowTitle(QCoreApplication::translate("ViewWindow", "Dialog", nullptr));
        pushButtongoBack->setText(QCoreApplication::translate("ViewWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        labelTitle->setText(QCoreApplication::translate("ViewWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \321\201\320\273\320\276\320\262\320\260\321\200\321\217", nullptr));
        label_current_dictionary->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ViewWindow: public Ui_ViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWWINDOW_H
