/********************************************************************************
** Form generated from reading UI file 'siform.ui'
**
** Created: Mon Oct 7 12:29:48 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIFORM_H
#define UI_SIFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SIForm
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_DataCollection;
    QPushButton *DC_saveButton;
    QPushButton *DC_dictateButton;
    QPushButton *DC_newButton;
    QGroupBox *buttonGroup_View;
    QRadioButton *RB_View_Endoscope;
    QRadioButton *RB_View_OR2;
    QRadioButton *RB_View_OR;
    QGroupBox *groupBox_Scale;
    QPushButton *scaleDecreaseButton;
    QPushButton *scaleIncreaseButton;
    QLineEdit *scaleLineEdit;
    QPushButton *okButton;
    QPushButton *connectionButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *startButton;
    QLineEdit *lineEdit_Time;
    QPushButton *loginButton;
    QPushButton *logoButton;
    QComboBox *cB_LeftTool;
    QComboBox *cB_RightTool;
    QWidget *tab2;
    QGroupBox *buttonGroup_CM;
    QRadioButton *rB_CM_1D;
    QRadioButton *rB_CM_PP;
    QLabel *label_4;
    QLCDNumber *lCDNumber2;
    QPushButton *A_okButton;
    QPushButton *A_startButton;
    QComboBox *cB_IP;
    QTextEdit *infoText;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *camAngle1;
    QDoubleSpinBox *camAngle2;
    QDoubleSpinBox *camAngle3;
    QCheckBox *ITPCheck;

    void setupUi(QDialog *SIForm)
    {
        if (SIForm->objectName().isEmpty())
            SIForm->setObjectName(QString::fromUtf8("SIForm"));
        SIForm->resize(800, 570);
        tabWidget = new QTabWidget(SIForm);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 800, 570));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(17);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setGeometry(QRect(0, 0, 794, 529));
        groupBox_DataCollection = new QGroupBox(tab);
        groupBox_DataCollection->setObjectName(QString::fromUtf8("groupBox_DataCollection"));
        groupBox_DataCollection->setGeometry(QRect(410, 395, 330, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        groupBox_DataCollection->setFont(font1);
        DC_saveButton = new QPushButton(groupBox_DataCollection);
        DC_saveButton->setObjectName(QString::fromUtf8("DC_saveButton"));
        DC_saveButton->setGeometry(QRect(115, 23, 100, 70));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(13);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        DC_saveButton->setFont(font2);
        DC_dictateButton = new QPushButton(groupBox_DataCollection);
        DC_dictateButton->setObjectName(QString::fromUtf8("DC_dictateButton"));
        DC_dictateButton->setGeometry(QRect(220, 23, 100, 70));
        DC_dictateButton->setFont(font2);
        DC_newButton = new QPushButton(groupBox_DataCollection);
        DC_newButton->setObjectName(QString::fromUtf8("DC_newButton"));
        DC_newButton->setGeometry(QRect(10, 23, 100, 70));
        DC_newButton->setFont(font2);
        buttonGroup_View = new QGroupBox(tab);
        buttonGroup_View->setObjectName(QString::fromUtf8("buttonGroup_View"));
        buttonGroup_View->setGeometry(QRect(410, 260, 330, 130));
        buttonGroup_View->setFont(font1);
        RB_View_Endoscope = new QRadioButton(buttonGroup_View);
        RB_View_Endoscope->setObjectName(QString::fromUtf8("RB_View_Endoscope"));
        RB_View_Endoscope->setGeometry(QRect(30, 24, 271, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        RB_View_Endoscope->setFont(font3);
        RB_View_OR2 = new QRadioButton(buttonGroup_View);
        RB_View_OR2->setObjectName(QString::fromUtf8("RB_View_OR2"));
        RB_View_OR2->setGeometry(QRect(30, 94, 271, 31));
        RB_View_OR2->setFont(font3);
        RB_View_OR = new QRadioButton(buttonGroup_View);
        RB_View_OR->setObjectName(QString::fromUtf8("RB_View_OR"));
        RB_View_OR->setGeometry(QRect(30, 59, 271, 31));
        RB_View_OR->setFont(font3);
        groupBox_Scale = new QGroupBox(tab);
        groupBox_Scale->setObjectName(QString::fromUtf8("groupBox_Scale"));
        groupBox_Scale->setGeometry(QRect(410, 155, 330, 105));
        scaleDecreaseButton = new QPushButton(groupBox_Scale);
        scaleDecreaseButton->setObjectName(QString::fromUtf8("scaleDecreaseButton"));
        scaleDecreaseButton->setGeometry(QRect(5, 28, 100, 70));
        scaleIncreaseButton = new QPushButton(groupBox_Scale);
        scaleIncreaseButton->setObjectName(QString::fromUtf8("scaleIncreaseButton"));
        scaleIncreaseButton->setGeometry(QRect(225, 28, 100, 70));
        scaleLineEdit = new QLineEdit(groupBox_Scale);
        scaleLineEdit->setObjectName(QString::fromUtf8("scaleLineEdit"));
        scaleLineEdit->setGeometry(QRect(110, 33, 110, 61));
        scaleLineEdit->setFocusPolicy(Qt::NoFocus);
        scaleLineEdit->setAlignment(Qt::AlignHCenter);
        scaleLineEdit->setReadOnly(true);
        okButton = new QPushButton(tab);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(580, 40, 160, 110));
        okButton->setFont(font1);
        connectionButton = new QPushButton(tab);
        connectionButton->setObjectName(QString::fromUtf8("connectionButton"));
        connectionButton->setGeometry(QRect(10, 110, 190, 100));
        connectionButton->setFont(font1);
        connectionButton->setAutoFillBackground(true);
        connectionButton->setIconSize(QSize(190, 100));
        connectionButton->setFlat(true);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 154, 21));
        label->setFont(font1);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 10, 171, 35));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(213, 130, 171, 23));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        startButton = new QPushButton(tab);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(4, 220, 390, 280));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(24);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setWeight(50);
        font4.setStrikeOut(false);
        startButton->setFont(font4);
        startButton->setIconSize(QSize(390, 280));
        startButton->setFlat(true);
        lineEdit_Time = new QLineEdit(tab);
        lineEdit_Time->setObjectName(QString::fromUtf8("lineEdit_Time"));
        lineEdit_Time->setGeometry(QRect(210, 160, 181, 41));
        lineEdit_Time->setFocusPolicy(Qt::NoFocus);
        lineEdit_Time->setReadOnly(true);
        loginButton = new QPushButton(tab);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(410, 40, 160, 110));
        loginButton->setFont(font1);
        logoButton = new QPushButton(tab);
        logoButton->setObjectName(QString::fromUtf8("logoButton"));
        logoButton->setGeometry(QRect(410, 10, 330, 25));
        logoButton->setIconSize(QSize(330, 25));
        logoButton->setFlat(true);
        cB_LeftTool = new QComboBox(tab);
        cB_LeftTool->setObjectName(QString::fromUtf8("cB_LeftTool"));
        cB_LeftTool->setGeometry(QRect(10, 49, 180, 51));
        cB_LeftTool->setFocusPolicy(Qt::NoFocus);
        cB_RightTool = new QComboBox(tab);
        cB_RightTool->setObjectName(QString::fromUtf8("cB_RightTool"));
        cB_RightTool->setGeometry(QRect(200, 49, 180, 51));
        cB_RightTool->setFocusPolicy(Qt::NoFocus);
        tabWidget->addTab(tab, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        tab2->setGeometry(QRect(0, 0, 794, 529));
        buttonGroup_CM = new QGroupBox(tab2);
        buttonGroup_CM->setObjectName(QString::fromUtf8("buttonGroup_CM"));
        buttonGroup_CM->setGeometry(QRect(0, 130, 360, 100));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(16);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setUnderline(false);
        font5.setWeight(50);
        font5.setStrikeOut(false);
        buttonGroup_CM->setFont(font5);
        rB_CM_1D = new QRadioButton(buttonGroup_CM);
        rB_CM_1D->setObjectName(QString::fromUtf8("rB_CM_1D"));
        rB_CM_1D->setGeometry(QRect(20, 36, 271, 17));
        rB_CM_1D->setFocusPolicy(Qt::NoFocus);
        rB_CM_PP = new QRadioButton(buttonGroup_CM);
        rB_CM_PP->setObjectName(QString::fromUtf8("rB_CM_PP"));
        rB_CM_PP->setGeometry(QRect(20, 68, 271, 17));
        rB_CM_PP->setFocusPolicy(Qt::NoFocus);
        label_4 = new QLabel(tab2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 240, 121, 27));
        lCDNumber2 = new QLCDNumber(tab2);
        lCDNumber2->setObjectName(QString::fromUtf8("lCDNumber2"));
        lCDNumber2->setGeometry(QRect(210, 10, 160, 35));
        A_okButton = new QPushButton(tab2);
        A_okButton->setObjectName(QString::fromUtf8("A_okButton"));
        A_okButton->setGeometry(QRect(210, 50, 160, 70));
        A_okButton->setFocusPolicy(Qt::NoFocus);
        A_startButton = new QPushButton(tab2);
        A_startButton->setObjectName(QString::fromUtf8("A_startButton"));
        A_startButton->setGeometry(QRect(10, 10, 191, 110));
        A_startButton->setFocusPolicy(Qt::NoFocus);
        A_startButton->setAutoFillBackground(true);
        A_startButton->setFlat(true);
        cB_IP = new QComboBox(tab2);
        cB_IP->setObjectName(QString::fromUtf8("cB_IP"));
        cB_IP->setGeometry(QRect(10, 270, 351, 51));
        cB_IP->setFont(font1);
        cB_IP->setFocusPolicy(Qt::NoFocus);
        infoText = new QTextEdit(tab2);
        infoText->setObjectName(QString::fromUtf8("infoText"));
        infoText->setGeometry(QRect(375, 10, 390, 510));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setPointSize(11);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setUnderline(false);
        font6.setWeight(50);
        font6.setStrikeOut(false);
        infoText->setFont(font6);
        infoText->setFocusPolicy(Qt::NoFocus);
        infoText->setReadOnly(true);
        label_5 = new QLabel(tab2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 350, 71, 20));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Arial"));
        font7.setPointSize(14);
        label_5->setFont(font7);
        label_6 = new QLabel(tab2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 380, 71, 20));
        label_6->setFont(font7);
        label_7 = new QLabel(tab2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 410, 71, 20));
        label_7->setFont(font7);
        camAngle1 = new QDoubleSpinBox(tab2);
        camAngle1->setObjectName(QString::fromUtf8("camAngle1"));
        camAngle1->setGeometry(QRect(100, 350, 101, 22));
        camAngle1->setMinimum(-180);
        camAngle1->setMaximum(180);
        camAngle2 = new QDoubleSpinBox(tab2);
        camAngle2->setObjectName(QString::fromUtf8("camAngle2"));
        camAngle2->setGeometry(QRect(100, 380, 101, 22));
        camAngle2->setMinimum(-180);
        camAngle2->setMaximum(180);
        camAngle3 = new QDoubleSpinBox(tab2);
        camAngle3->setObjectName(QString::fromUtf8("camAngle3"));
        camAngle3->setGeometry(QRect(100, 410, 101, 22));
        camAngle3->setMinimum(-180);
        camAngle3->setMaximum(180);
        ITPCheck = new QCheckBox(tab2);
        ITPCheck->setObjectName(QString::fromUtf8("ITPCheck"));
        ITPCheck->setEnabled(true);
        ITPCheck->setGeometry(QRect(30, 450, 311, 21));
        tabWidget->addTab(tab2, QString());

        retranslateUi(SIForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SIForm);
    } // setupUi

    void retranslateUi(QDialog *SIForm)
    {
        SIForm->setWindowTitle(QApplication::translate("SIForm", "Surgeon's GUI for a BRL's Laparoscopic Robot System", 0, QApplication::UnicodeUTF8));
        groupBox_DataCollection->setTitle(QApplication::translate("SIForm", "Data Connection", 0, QApplication::UnicodeUTF8));
        DC_saveButton->setText(QApplication::translate("SIForm", "Start", 0, QApplication::UnicodeUTF8));
        DC_dictateButton->setText(QApplication::translate("SIForm", "Dictate Note", 0, QApplication::UnicodeUTF8));
        DC_newButton->setText(QApplication::translate("SIForm", "Generate\n"
"New File", 0, QApplication::UnicodeUTF8));
        buttonGroup_View->setTitle(QApplication::translate("SIForm", "Video Source Select ", 0, QApplication::UnicodeUTF8));
        RB_View_Endoscope->setText(QApplication::translate("SIForm", "Endoscopic View", 0, QApplication::UnicodeUTF8));
        RB_View_OR2->setText(QApplication::translate("SIForm", "Operating Room View 2", 0, QApplication::UnicodeUTF8));
        RB_View_OR->setText(QApplication::translate("SIForm", "Operating Room View 1", 0, QApplication::UnicodeUTF8));
        groupBox_Scale->setTitle(QApplication::translate("SIForm", "Scale", 0, QApplication::UnicodeUTF8));
        scaleDecreaseButton->setText(QApplication::translate("SIForm", "<<", 0, QApplication::UnicodeUTF8));
        scaleIncreaseButton->setText(QApplication::translate("SIForm", ">>", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("SIForm", "CLOSE GUI", 0, QApplication::UnicodeUTF8));
        connectionButton->setText(QApplication::translate("SIForm", "Connection Status", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SIForm", "Left Hand Tool", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SIForm", "Right Hand Tool", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SIForm", "Elapsed Surgery Time", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("SIForm", "Start", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("SIForm", "Now Logined\n"
"Press to log-out", 0, QApplication::UnicodeUTF8));
        logoButton->setText(QApplication::translate("SIForm", "bioRobotics Laboratory", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SIForm", "Surgeon", 0, QApplication::UnicodeUTF8));
        buttonGroup_CM->setTitle(QApplication::translate("SIForm", "Select Control Mode", 0, QApplication::UnicodeUTF8));
        rB_CM_1D->setText(QApplication::translate("SIForm", "One Directional Control", 0, QApplication::UnicodeUTF8));
        rB_CM_PP->setText(QApplication::translate("SIForm", "Position-Position Control", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SIForm", "IP Address", 0, QApplication::UnicodeUTF8));
        A_okButton->setText(QApplication::translate("SIForm", "CLOSE GUI", 0, QApplication::UnicodeUTF8));
        A_startButton->setText(QApplication::translate("SIForm", "START", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SIForm", "Theta 1", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SIForm", "Theta 2", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SIForm", "Theta 3", 0, QApplication::UnicodeUTF8));
        ITPCheck->setText(QApplication::translate("SIForm", "Use ITP Reference Frame", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("SIForm", "Engineer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SIForm: public Ui_SIForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIFORM_H
