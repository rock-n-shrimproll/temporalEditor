/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_view;
    QPushButton *pushButton_edit;
    QPushButton *pushButton;
    QLabel *label;
    QGroupBox *groupBox_part_of_speech;
    QRadioButton *radioButton_noun;
    QRadioButton *radioButton_adj;
    QRadioButton *radioButton_pronoun;
    QRadioButton *radioButton_adv;
    QRadioButton *radioButton_prep;
    QMenuBar *menubar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(510, 289);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_view = new QPushButton(centralwidget);
        pushButton_view->setObjectName(QString::fromUtf8("pushButton_view"));

        gridLayout->addWidget(pushButton_view, 9, 2, 1, 1);

        pushButton_edit = new QPushButton(centralwidget);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));

        gridLayout->addWidget(pushButton_edit, 9, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(254, 161));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        groupBox_part_of_speech = new QGroupBox(centralwidget);
        groupBox_part_of_speech->setObjectName(QString::fromUtf8("groupBox_part_of_speech"));
        radioButton_noun = new QRadioButton(groupBox_part_of_speech);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton_noun);
        radioButton_noun->setObjectName(QString::fromUtf8("radioButton_noun"));
        radioButton_noun->setGeometry(QRect(20, 30, 231, 20));
        radioButton_noun->setMinimumSize(QSize(231, 0));
        radioButton_noun->setMaximumSize(QSize(231, 20));
        QFont font1;
        font1.setPointSize(17);
        radioButton_noun->setFont(font1);
        radioButton_adj = new QRadioButton(groupBox_part_of_speech);
        buttonGroup->addButton(radioButton_adj);
        radioButton_adj->setObjectName(QString::fromUtf8("radioButton_adj"));
        radioButton_adj->setGeometry(QRect(20, 60, 451, 20));
        radioButton_adj->setFont(font1);
        radioButton_pronoun = new QRadioButton(groupBox_part_of_speech);
        buttonGroup->addButton(radioButton_pronoun);
        radioButton_pronoun->setObjectName(QString::fromUtf8("radioButton_pronoun"));
        radioButton_pronoun->setGeometry(QRect(20, 90, 451, 20));
        radioButton_pronoun->setFont(font1);
        radioButton_adv = new QRadioButton(groupBox_part_of_speech);
        buttonGroup->addButton(radioButton_adv);
        radioButton_adv->setObjectName(QString::fromUtf8("radioButton_adv"));
        radioButton_adv->setGeometry(QRect(20, 120, 100, 20));
        radioButton_adv->setFont(font1);
        radioButton_prep = new QRadioButton(groupBox_part_of_speech);
        buttonGroup->addButton(radioButton_prep);
        radioButton_prep->setObjectName(QString::fromUtf8("radioButton_prep"));
        radioButton_prep->setGeometry(QRect(20, 150, 371, 20));
        radioButton_prep->setFont(font1);

        gridLayout->addWidget(groupBox_part_of_speech, 2, 0, 2, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 510, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
        pushButton_view->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
        pushButton_edit->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\320\273\320\276\320\262\320\260\321\200\321\214", nullptr));
        groupBox_part_of_speech->setTitle(QCoreApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\270 \321\200\320\265\321\207\320\270:", nullptr));
        radioButton_noun->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\321\211\320\265\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265", nullptr));
        radioButton_adj->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\273\320\260\320\263\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\265", nullptr));
        radioButton_pronoun->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276\320\270\320\274\320\265\320\275\320\270\321\217", nullptr));
        radioButton_adv->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\200\320\265\321\207\320\270\321\217", nullptr));
        radioButton_prep->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\320\273\320\276\320\263\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
