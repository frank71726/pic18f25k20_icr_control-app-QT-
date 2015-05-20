/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QWidget *centralWidget;
    QPushButton *but_start;
    QLabel *uart_status;
    QPushButton *but_reset;
    QGroupBox *func_group;
    QVBoxLayout *verticalLayout;
    QCheckBox *all_test;
    QCheckBox *degree_0;
    QCheckBox *degree_90;
    QCheckBox *degree_180;
    QComboBox *icr_time_sel;
    QLabel *label;
    QDial *voltage_dial;
    QSpinBox *voltage_Box;
    QLabel *icr_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *icr_2;
    QLabel *icr_3;
    QLabel *icr_4;
    QLabel *icr_5;
    QPushButton *but_auto;
    QLabel *label_7;
    QLabel *icr1_ok;
    QLabel *label_9;
    QLabel *icr1_ng;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *icr2_ok;
    QLabel *icr2_ng;
    QLabel *icr3_ok;
    QLabel *icr3_ng;
    QLabel *icr4_ok;
    QLabel *icr4_ng;
    QLabel *icr5_ok;
    QLabel *icr5_ng;
    QLabel *count_down;
    QLabel *label_17;
    QPushButton *but_stop;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(546, 499);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon1);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon2);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        but_start = new QPushButton(centralWidget);
        but_start->setObjectName(QStringLiteral("but_start"));
        but_start->setEnabled(false);
        but_start->setGeometry(QRect(270, 10, 130, 51));
        QFont font;
        font.setPointSize(32);
        font.setBold(true);
        font.setWeight(75);
        but_start->setFont(font);
        uart_status = new QLabel(centralWidget);
        uart_status->setObjectName(QStringLiteral("uart_status"));
        uart_status->setGeometry(QRect(10, 320, 511, 81));
        QFont font1;
        font1.setPointSize(48);
        uart_status->setFont(font1);
        uart_status->setLayoutDirection(Qt::LeftToRight);
        uart_status->setAlignment(Qt::AlignCenter);
        but_reset = new QPushButton(centralWidget);
        but_reset->setObjectName(QStringLiteral("but_reset"));
        but_reset->setEnabled(true);
        but_reset->setGeometry(QRect(410, 10, 130, 191));
        but_reset->setFont(font);
        func_group = new QGroupBox(centralWidget);
        func_group->setObjectName(QStringLiteral("func_group"));
        func_group->setEnabled(false);
        func_group->setGeometry(QRect(10, 10, 131, 161));
        verticalLayout = new QVBoxLayout(func_group);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        all_test = new QCheckBox(func_group);
        all_test->setObjectName(QStringLiteral("all_test"));

        verticalLayout->addWidget(all_test);

        degree_0 = new QCheckBox(func_group);
        degree_0->setObjectName(QStringLiteral("degree_0"));

        verticalLayout->addWidget(degree_0);

        degree_90 = new QCheckBox(func_group);
        degree_90->setObjectName(QStringLiteral("degree_90"));

        verticalLayout->addWidget(degree_90);

        degree_180 = new QCheckBox(func_group);
        degree_180->setObjectName(QStringLiteral("degree_180"));

        verticalLayout->addWidget(degree_180);

        icr_time_sel = new QComboBox(centralWidget);
        icr_time_sel->setObjectName(QStringLiteral("icr_time_sel"));
        icr_time_sel->setEnabled(false);
        icr_time_sel->setGeometry(QRect(150, 40, 85, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 101, 21));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        voltage_dial = new QDial(centralWidget);
        voltage_dial->setObjectName(QStringLiteral("voltage_dial"));
        voltage_dial->setGeometry(QRect(150, 80, 81, 81));
        voltage_dial->setMinimum(1);
        voltage_dial->setMaximum(64);
        voltage_dial->setValue(1);
        voltage_Box = new QSpinBox(centralWidget);
        voltage_Box->setObjectName(QStringLiteral("voltage_Box"));
        voltage_Box->setEnabled(false);
        voltage_Box->setGeometry(QRect(160, 170, 81, 27));
        voltage_Box->setMinimum(500);
        voltage_Box->setMaximum(3650);
        voltage_Box->setSingleStep(50);
        voltage_Box->setValue(500);
        icr_1 = new QLabel(centralWidget);
        icr_1->setObjectName(QStringLiteral("icr_1"));
        icr_1->setGeometry(QRect(20, 240, 40, 40));
        icr_1->setMinimumSize(QSize(0, 0));
        icr_1->setBaseSize(QSize(0, 0));
        icr_1->setLineWidth(1);
        icr_1->setMargin(5);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 210, 41, 17));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 210, 51, 17));
        QFont font4;
        font4.setBold(true);
        font4.setUnderline(true);
        font4.setWeight(75);
        label_3->setFont(font4);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 210, 41, 17));
        label_4->setFont(font4);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 210, 41, 17));
        label_5->setFont(font4);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(420, 210, 51, 17));
        label_6->setFont(font4);
        icr_2 = new QLabel(centralWidget);
        icr_2->setObjectName(QStringLiteral("icr_2"));
        icr_2->setGeometry(QRect(120, 240, 40, 40));
        icr_2->setMinimumSize(QSize(0, 0));
        icr_2->setBaseSize(QSize(0, 0));
        icr_2->setLineWidth(1);
        icr_2->setMargin(5);
        icr_3 = new QLabel(centralWidget);
        icr_3->setObjectName(QStringLiteral("icr_3"));
        icr_3->setGeometry(QRect(220, 240, 40, 40));
        icr_3->setMinimumSize(QSize(0, 0));
        icr_3->setBaseSize(QSize(0, 0));
        icr_3->setLineWidth(1);
        icr_3->setMargin(5);
        icr_4 = new QLabel(centralWidget);
        icr_4->setObjectName(QStringLiteral("icr_4"));
        icr_4->setGeometry(QRect(320, 240, 40, 40));
        icr_4->setMinimumSize(QSize(0, 0));
        icr_4->setBaseSize(QSize(0, 0));
        icr_4->setLineWidth(1);
        icr_4->setMargin(5);
        icr_5 = new QLabel(centralWidget);
        icr_5->setObjectName(QStringLiteral("icr_5"));
        icr_5->setGeometry(QRect(420, 240, 40, 40));
        icr_5->setMinimumSize(QSize(0, 0));
        icr_5->setBaseSize(QSize(0, 0));
        icr_5->setLineWidth(1);
        icr_5->setMargin(5);
        but_auto = new QPushButton(centralWidget);
        but_auto->setObjectName(QStringLiteral("but_auto"));
        but_auto->setEnabled(false);
        but_auto->setGeometry(QRect(270, 70, 131, 91));
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        but_auto->setFont(font5);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 230, 41, 17));
        icr1_ok = new QLabel(centralWidget);
        icr1_ok->setObjectName(QStringLiteral("icr1_ok"));
        icr1_ok->setGeometry(QRect(70, 250, 41, 17));
        icr1_ok->setFont(font4);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(70, 270, 41, 17));
        icr1_ng = new QLabel(centralWidget);
        icr1_ng->setObjectName(QStringLiteral("icr1_ng"));
        icr1_ng->setGeometry(QRect(70, 290, 41, 17));
        icr1_ng->setFont(font4);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(170, 230, 41, 17));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(270, 230, 41, 17));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(370, 230, 41, 17));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(470, 230, 41, 17));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(170, 270, 41, 17));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(270, 270, 41, 17));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(370, 270, 41, 17));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(470, 270, 41, 17));
        icr2_ok = new QLabel(centralWidget);
        icr2_ok->setObjectName(QStringLiteral("icr2_ok"));
        icr2_ok->setGeometry(QRect(170, 250, 41, 17));
        icr2_ok->setFont(font4);
        icr2_ng = new QLabel(centralWidget);
        icr2_ng->setObjectName(QStringLiteral("icr2_ng"));
        icr2_ng->setGeometry(QRect(170, 290, 41, 17));
        icr2_ng->setFont(font4);
        icr3_ok = new QLabel(centralWidget);
        icr3_ok->setObjectName(QStringLiteral("icr3_ok"));
        icr3_ok->setGeometry(QRect(270, 250, 41, 17));
        icr3_ok->setFont(font4);
        icr3_ng = new QLabel(centralWidget);
        icr3_ng->setObjectName(QStringLiteral("icr3_ng"));
        icr3_ng->setGeometry(QRect(270, 290, 41, 17));
        icr3_ng->setFont(font4);
        icr4_ok = new QLabel(centralWidget);
        icr4_ok->setObjectName(QStringLiteral("icr4_ok"));
        icr4_ok->setGeometry(QRect(370, 250, 41, 17));
        icr4_ok->setFont(font4);
        icr4_ng = new QLabel(centralWidget);
        icr4_ng->setObjectName(QStringLiteral("icr4_ng"));
        icr4_ng->setGeometry(QRect(370, 290, 41, 17));
        icr4_ng->setFont(font4);
        icr5_ok = new QLabel(centralWidget);
        icr5_ok->setObjectName(QStringLiteral("icr5_ok"));
        icr5_ok->setGeometry(QRect(470, 250, 41, 17));
        icr5_ok->setFont(font4);
        icr5_ng = new QLabel(centralWidget);
        icr5_ng->setObjectName(QStringLiteral("icr5_ng"));
        icr5_ng->setGeometry(QRect(470, 290, 41, 17));
        icr5_ng->setFont(font4);
        count_down = new QLabel(centralWidget);
        count_down->setObjectName(QStringLiteral("count_down"));
        count_down->setGeometry(QRect(20, 190, 121, 21));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setItalic(true);
        font6.setWeight(75);
        count_down->setFont(font6);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 170, 151, 20));
        QFont font7;
        font7.setBold(true);
        font7.setItalic(true);
        font7.setWeight(75);
        label_17->setFont(font7);
        but_stop = new QPushButton(centralWidget);
        but_stop->setObjectName(QStringLiteral("but_stop"));
        but_stop->setEnabled(false);
        but_stop->setGeometry(QRect(270, 170, 131, 31));
        but_stop->setFont(font5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 546, 17));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QStringLiteral("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simple Terminal", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "C&onnect", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", 0));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from serial port", 0));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", 0));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", 0));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear data", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        but_start->setText(QApplication::translate("MainWindow", "START", 0));
        uart_status->setText(QApplication::translate("MainWindow", "STOP", 0));
        but_reset->setText(QApplication::translate("MainWindow", "RESET", 0));
        func_group->setTitle(QApplication::translate("MainWindow", "Selsec Function", 0));
        all_test->setText(QApplication::translate("MainWindow", "All Test", 0));
        degree_0->setText(QApplication::translate("MainWindow", "0 degree", 0));
        degree_90->setText(QApplication::translate("MainWindow", "90 degree", 0));
        degree_180->setText(QApplication::translate("MainWindow", "180 degree", 0));
        icr_time_sel->clear();
        icr_time_sel->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "100", 0)
         << QApplication::translate("MainWindow", "200", 0)
         << QApplication::translate("MainWindow", "300", 0)
         << QApplication::translate("MainWindow", "400", 0)
         << QApplication::translate("MainWindow", "500", 0)
         << QApplication::translate("MainWindow", "600", 0)
         << QApplication::translate("MainWindow", "700", 0)
         << QApplication::translate("MainWindow", "800", 0)
         << QApplication::translate("MainWindow", "900", 0)
         << QApplication::translate("MainWindow", "1000", 0)
        );
        label->setText(QApplication::translate("MainWindow", "ICT time", 0));
        voltage_Box->setSuffix(QApplication::translate("MainWindow", " mV", 0));
        voltage_Box->setPrefix(QString());
        icr_1->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "ICR_1", 0));
        label_3->setText(QApplication::translate("MainWindow", "ICR_2", 0));
        label_4->setText(QApplication::translate("MainWindow", "ICR_3", 0));
        label_5->setText(QApplication::translate("MainWindow", "ICR_4", 0));
        label_6->setText(QApplication::translate("MainWindow", "ICR_5", 0));
        icr_2->setText(QString());
        icr_3->setText(QString());
        icr_4->setText(QString());
        icr_5->setText(QString());
        but_auto->setText(QApplication::translate("MainWindow", "Auto Test", 0));
        label_7->setText(QApplication::translate("MainWindow", "OK", 0));
        icr1_ok->setText(QApplication::translate("MainWindow", "0", 0));
        label_9->setText(QApplication::translate("MainWindow", "NG", 0));
        icr1_ng->setText(QApplication::translate("MainWindow", "0", 0));
        label_8->setText(QApplication::translate("MainWindow", "OK", 0));
        label_10->setText(QApplication::translate("MainWindow", "OK", 0));
        label_11->setText(QApplication::translate("MainWindow", "OK", 0));
        label_12->setText(QApplication::translate("MainWindow", "OK", 0));
        label_13->setText(QApplication::translate("MainWindow", "NG", 0));
        label_14->setText(QApplication::translate("MainWindow", "NG", 0));
        label_15->setText(QApplication::translate("MainWindow", "NG", 0));
        label_16->setText(QApplication::translate("MainWindow", "NG", 0));
        icr2_ok->setText(QApplication::translate("MainWindow", "0", 0));
        icr2_ng->setText(QApplication::translate("MainWindow", "0", 0));
        icr3_ok->setText(QApplication::translate("MainWindow", "0", 0));
        icr3_ng->setText(QApplication::translate("MainWindow", "0", 0));
        icr4_ok->setText(QApplication::translate("MainWindow", "0", 0));
        icr4_ng->setText(QApplication::translate("MainWindow", "0", 0));
        icr5_ok->setText(QApplication::translate("MainWindow", "0", 0));
        icr5_ng->setText(QApplication::translate("MainWindow", "0", 0));
        count_down->setText(QApplication::translate("MainWindow", "Rest sec", 0));
        label_17->setText(QApplication::translate("MainWindow", "Count down second", 0));
        but_stop->setText(QApplication::translate("MainWindow", "STOP", 0));
        menuCalls->setTitle(QApplication::translate("MainWindow", "Calls", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
