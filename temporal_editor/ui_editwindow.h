/********************************************************************************
** Form generated from reading UI file 'editwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWINDOW_H
#define UI_EDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditWindow
{
public:
    QPushButton *pushButtongoBack;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelTitle;
    QLabel *label_qmff;
    QComboBox *comboBoxDeclension;
    QLabel *label_qmtemp;
    QPushButton *pushButtonAddToDict;
    QLabel *label_qmdt;
    QLabel *label_temporality;
    QLabel *label_first_form;
    QLabel *label_quazibase;
    QLabel *label_declension_type;
    QLineEdit *lineEditQuasibase;
    QLineEdit *lineEditFirstform;
    QSpinBox *spinBoxTemporality;
    QLabel *label_qmqb;
    QLabel *label_current_dictionary;

    void setupUi(QDialog *EditWindow)
    {
        if (EditWindow->objectName().isEmpty())
            EditWindow->setObjectName(QString::fromUtf8("EditWindow"));
        EditWindow->resize(550, 398);
        pushButtongoBack = new QPushButton(EditWindow);
        pushButtongoBack->setObjectName(QString::fromUtf8("pushButtongoBack"));
        pushButtongoBack->setGeometry(QRect(0, 20, 81, 31));
        gridLayoutWidget = new QWidget(EditWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 60, 453, 285));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(gridLayoutWidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));

        gridLayout->addWidget(labelTitle, 1, 0, 1, 1);

        label_qmff = new QLabel(gridLayoutWidget);
        label_qmff->setObjectName(QString::fromUtf8("label_qmff"));
        label_qmff->setLayoutDirection(Qt::LeftToRight);
        label_qmff->setPixmap(QPixmap(QString::fromUtf8("qm.png")));
        label_qmff->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label_qmff, 2, 2, 1, 1);

        comboBoxDeclension = new QComboBox(gridLayoutWidget);
        comboBoxDeclension->setObjectName(QString::fromUtf8("comboBoxDeclension"));

        gridLayout->addWidget(comboBoxDeclension, 4, 1, 1, 1);

        label_qmtemp = new QLabel(gridLayoutWidget);
        label_qmtemp->setObjectName(QString::fromUtf8("label_qmtemp"));
        label_qmtemp->setPixmap(QPixmap(QString::fromUtf8("qm.png")));

        gridLayout->addWidget(label_qmtemp, 5, 2, 1, 1);

        pushButtonAddToDict = new QPushButton(gridLayoutWidget);
        pushButtonAddToDict->setObjectName(QString::fromUtf8("pushButtonAddToDict"));

        gridLayout->addWidget(pushButtonAddToDict, 6, 1, 1, 1);

        label_qmdt = new QLabel(gridLayoutWidget);
        label_qmdt->setObjectName(QString::fromUtf8("label_qmdt"));
        label_qmdt->setPixmap(QPixmap(QString::fromUtf8("qm.png")));

        gridLayout->addWidget(label_qmdt, 4, 2, 1, 1);

        label_temporality = new QLabel(gridLayoutWidget);
        label_temporality->setObjectName(QString::fromUtf8("label_temporality"));

        gridLayout->addWidget(label_temporality, 5, 0, 1, 1);

        label_first_form = new QLabel(gridLayoutWidget);
        label_first_form->setObjectName(QString::fromUtf8("label_first_form"));

        gridLayout->addWidget(label_first_form, 2, 0, 1, 1);

        label_quazibase = new QLabel(gridLayoutWidget);
        label_quazibase->setObjectName(QString::fromUtf8("label_quazibase"));

        gridLayout->addWidget(label_quazibase, 3, 0, 1, 1);

        label_declension_type = new QLabel(gridLayoutWidget);
        label_declension_type->setObjectName(QString::fromUtf8("label_declension_type"));

        gridLayout->addWidget(label_declension_type, 4, 0, 1, 1);

        lineEditQuasibase = new QLineEdit(gridLayoutWidget);
        lineEditQuasibase->setObjectName(QString::fromUtf8("lineEditQuasibase"));

        gridLayout->addWidget(lineEditQuasibase, 3, 1, 1, 1);

        lineEditFirstform = new QLineEdit(gridLayoutWidget);
        lineEditFirstform->setObjectName(QString::fromUtf8("lineEditFirstform"));

        gridLayout->addWidget(lineEditFirstform, 2, 1, 1, 1);

        spinBoxTemporality = new QSpinBox(gridLayoutWidget);
        spinBoxTemporality->setObjectName(QString::fromUtf8("spinBoxTemporality"));

        gridLayout->addWidget(spinBoxTemporality, 5, 1, 1, 1);

        label_qmqb = new QLabel(gridLayoutWidget);
        label_qmqb->setObjectName(QString::fromUtf8("label_qmqb"));
        label_qmqb->setPixmap(QPixmap(QString::fromUtf8("qm.png")));

        gridLayout->addWidget(label_qmqb, 3, 2, 1, 1);

        label_current_dictionary = new QLabel(gridLayoutWidget);
        label_current_dictionary->setObjectName(QString::fromUtf8("label_current_dictionary"));

        gridLayout->addWidget(label_current_dictionary, 1, 1, 1, 1);


        retranslateUi(EditWindow);

        QMetaObject::connectSlotsByName(EditWindow);
    } // setupUi

    void retranslateUi(QDialog *EditWindow)
    {
        EditWindow->setWindowTitle(QCoreApplication::translate("EditWindow", "Dialog", nullptr));
        pushButtongoBack->setText(QCoreApplication::translate("EditWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        labelTitle->setText(QCoreApplication::translate("EditWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 ", nullptr));
        label_qmff->setText(QString());
        label_qmtemp->setText(QString());
        pushButtonAddToDict->setText(QCoreApplication::translate("EditWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\273\320\265\320\272\321\201\320\265\320\274\321\203 \320\262 \321\201\320\273\320\276\320\262\320\260\321\200\321\214", nullptr));
        label_qmdt->setText(QString());
        label_temporality->setText(QCoreApplication::translate("EditWindow", "\320\242\320\265\320\274\320\277\320\276\321\200\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_first_form->setText(QCoreApplication::translate("EditWindow", "\320\244\320\276\321\200\320\274\320\260", nullptr));
        label_quazibase->setText(QCoreApplication::translate("EditWindow", "\320\232\320\262\320\260\320\267\320\270\320\276\321\201\320\275\320\276\320\262\320\260", nullptr));
        label_declension_type->setText(QCoreApplication::translate("EditWindow", "\320\242\320\270\320\277 \321\201\320\272\320\273\320\276\320\275\320\265\320\275\320\270\321\217", nullptr));
        label_qmqb->setText(QString());
        label_current_dictionary->setText(QCoreApplication::translate("EditWindow", "\321\202\321\203\321\202 \320\261\321\203\320\264\320\265\321\202 \321\201\320\273\320\276\320\262\320\260\321\200\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditWindow: public Ui_EditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
