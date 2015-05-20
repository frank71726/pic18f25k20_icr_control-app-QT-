/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QTime>

#define LINUX_VERSION
//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //! [0]
    ui->setupUi(this);
    console = new Console;
    console->setEnabled(false);
    console->setFixedSize(500,500);

    //  setCentralWidget(console);
    //! [1]
    serial = new QSerialPort(this);
    //! [1]
    settings = new SettingsDialog;

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    ui->icr_1->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_2->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_3->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_4->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_5->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->count_down->setStyleSheet("background-color: rgb(0, 250, 0);font-size:20px;color:blue");
    ui->icr1_ok->setStyleSheet("color:blue");
    ui->icr2_ok->setStyleSheet("color:blue");
    ui->icr3_ok->setStyleSheet("color:blue");
    ui->icr4_ok->setStyleSheet("color:blue");
    ui->icr5_ok->setStyleSheet("color:blue");
    ui->icr1_ng->setStyleSheet("color:red");
    ui->icr2_ng->setStyleSheet("color:red");
    ui->icr3_ng->setStyleSheet("color:red");
    ui->icr4_ng->setStyleSheet("color:red");
    ui->icr5_ng->setStyleSheet("color:red");

    for(int k=0; k<5; k++)
    {
        icr_ng_times[k] = 0;
        ng_count_times[k] = 0;
        ok_count_times[k] = 0;
    }
    reset_flag = 0;


    initActionsConnections();

    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
            SLOT(handleError(QSerialPort::SerialPortError)));

    //! [2]
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    //! [2]
    connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));
    //! [3]
}
//! [3]

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}

//! [4]
void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        console->setEnabled(true);
        console->setVisible(true);
        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                   .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                   .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        ui->statusBar->showMessage(tr("Open error"));
    }
}
//! [4]

//! [5]
void MainWindow::closeSerialPort()
{
    serial->close();
    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    ui->statusBar->showMessage(tr("Disconnected"));
}
//! [5]

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

//! [6]
void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}
//! [6]

//! [7]



void MainWindow::readData()
{
    QByteArray MSG_Start("$Please select icr time , than push start button#");//"$f00";
    QByteArray MSG_init("$please input $00(all), $01(0 degree), $02(90 degree), $03(180 degree)#");//"$f01";
    QByteArray MSG_AllTest("$Starting all test (0, 90, 180 degree)#");//"$f02";
    QByteArray MSG_0_degree("$Starting 0 degree test#");//"$f03";
    QByteArray MSG_90_degree("$Starting 90 degree test#");//"$f04";
    QByteArray MSG_180_degree("$Starting 180 degree test#");//"$f05";
    QByteArray MSG_Ok_1("$test ICR_1  OK#");//"$f16";
    QByteArray MSG_Ok_2("$test ICR_2  OK#");//"$f26";
    QByteArray MSG_Ok_3("$test ICR_3  OK#");//"$f36";
    QByteArray MSG_Ok_4("$test ICR_4  OK#");//"$f46";
    QByteArray MSG_Ok_5("$test ICR_5  OK#");//"$f56";
    QByteArray MSG_Ng_1("$test ICR_1  NG#");//"$f17";
    QByteArray MSG_Ng_2("$test ICR_2  NG#");//"$f27";
    QByteArray MSG_Ng_3("$test ICR_3  NG#");//"$f37";
    QByteArray MSG_Ng_4("$test ICR_4  NG#");//"$f47";
    QByteArray MSG_Ng_5("$test ICR_5  NG#");//"$f57";
    QByteArray MSG_Finish("$test finish#");//"$f08";
    QByteArray MSG_XXX("$XXX #");
    QByteArray MSG_YYY("$YYY #");
    //char *sec_reminder[11]={"0","1","2","3","4","5","6","7","8","9","10"};

    static int icr_ng_times[5]={0};
    //static double ng_count_times[5]={0};
    //static double ok_count_times[5]={0};


    static int step=0;
    QByteArray index_1("\n");
    QByteArray index_7("@");

    QByteArray get_data = serial->readAll();
    static QByteArray f_data, data;
    int num;
    int num_start;
    int num_end;

    if((step == 0) && (get_data.indexOf(index_1) == -1))
        return;
    else if(step == 0)
    {
        step=1;
        f_data = get_data;

        if(f_data.count() < 8)
            return;
        else
        {
            step = 2;
        }
    }
    else
    {}

    if((step == 1) || (step == 2))
    {
        if(step == 1)
            f_data += get_data;
        else
        {}
        if(f_data.indexOf(index_7) == -1)
            return;
        num = f_data.count();
        if(num < 7)
        {
            return;
        }
        else
        {
            num_start = f_data.indexOf(index_1);
            num_end = f_data.indexOf(index_7);

            for(int i=num_start; i<=num_end; i++)
                data += f_data[i];
            if(data.count() != 7)
            {
                step = 0;
                return;
            }
        }
        step = 0;
    }


    console->putData(data);

    if((data[2] == '$') && (data[3] == 'f') && (data[4] == '0') && (data[5] == '0')) {

        ui->uart_status->setText("MSG_Start");
        console->putData(MSG_Start);
        ui->but_start->setEnabled(true);
        ui->icr_time_sel->setEnabled(true);
        ui->voltage_Box->setEnabled(true);
        ui->voltage_dial->setEnabled(true);
    }
    else if((data[2] == '$') && (data[3] == 'f') && (data[4] == '0') && (data[5] == '1')) {

        ui->uart_status->setText("MSG_init");
        console->putData(MSG_init);
        //for auto test
        ui->func_group->setEnabled(false);
        ui->but_start->setEnabled(false);
        ui->but_auto->setEnabled(true);
    }
    else if((data[2] == '$') && (data[3] == 'f') && (data[4] == '0') && (data[5] == '2')) {

        ui->uart_status->setText("MSG_AllTest");
        console->putData(MSG_AllTest);
    }
    else if((data[2] == '$') && (data[3] == 'f') && (data[4] == '0') && (data[5] == '3')) {
        ui->uart_status->setStyleSheet("background-color: rgb(0, 250, 0);font-size:60px;color:blue");
        ui->uart_status->setText("MSG_0_degree");
        console->putData(MSG_0_degree);
    }
    else if((data[2] == '$') && (data[3] == 'f') && (data[4] == '0') && (data[5] == '4')) {
        ui->uart_status->setStyleSheet("background-color: rgb(0, 250, 0);font-size:60px;color:blue");
        ui->uart_status->setText("MSG_90_degree");
        console->putData(MSG_90_degree);
    }
    else if((data[2] == '$') && (data[3] == 'f') && (data[4] == '0') && (data[5] == '5')) {
        ui->uart_status->setStyleSheet("background-color: rgb(0, 250, 0);font-size:60px;color:blue");
        ui->uart_status->setText("MSG_180_degree");
        console->putData(MSG_180_degree);
    }
    else if((data[2] == '$') && (data[3] == 'f') && (data[5] == '6')) {
        ui->uart_status->setStyleSheet("background-color: rgb(0, 255, 0);font-size:60px;color:blue");

        if (data[4] == '1')
        {
            ui->uart_status->setText("MSG_Ok ICR_1"); console->putData(MSG_Ok_1);
            ok_count_times[0] += 1;
        }
        else if (data[4] == '2')
        {
            ui->uart_status->setText("MSG_Ok ICR_2"); console->putData(MSG_Ok_2);
            ok_count_times[1] += 1;
        }
        else if (data[4] == '3')
        {
            ui->uart_status->setText("MSG_Ok ICR_3"); console->putData(MSG_Ok_3);
            ok_count_times[2] += 1;
        }
        else if (data[4] == '4')
        {
            ui->uart_status->setText("MSG_Ok ICR_4"); console->putData(MSG_Ok_4);
            ok_count_times[3] += 1;
        }
        else if (data[4] == '5')
        {
            ui->uart_status->setText("MSG_Ok ICR_5"); console->putData(MSG_Ok_5);
            ok_count_times[4] += 1;
        }
        else
        {
            ui->uart_status->setText("MSG_XXX"); console->putData(MSG_XXX);
        }
        //console->putData(MSG_Ok);
    }
    else if((data[2] == '$') && (data[3] == 'f') && (data[5] == '7')) {
        ui->uart_status->setStyleSheet("background-color: rgb(250, 0, 0);font-size:60px;color:blue");

        if (data[4] == '1')
        {
            ui->uart_status->setText("MSG_Ng ICR_1"); console->putData(MSG_Ng_1); icr_ng_times[0] =1;
            ng_count_times[0] += 1;
        }
        else if (data[4] == '2')
        {
            ui->uart_status->setText("MSG_Ng ICR_2"); console->putData(MSG_Ng_2); icr_ng_times[1] =1;
            ng_count_times[1] += 1;
        }
        else if (data[4] == '3')
        {
            ui->uart_status->setText("MSG_Ng ICR_3"); console->putData(MSG_Ng_3); icr_ng_times[2] =1;
            ng_count_times[2] += 1;
        }
        else if (data[4] == '4')
        {
            ui->uart_status->setText("MSG_Ng ICR_4"); console->putData(MSG_Ng_4); icr_ng_times[3] =1;
            ng_count_times[3] += 1;
        }
        else if (data[4] == '5')
        {
            ui->uart_status->setText("MSG_Ng ICR_5"); console->putData(MSG_Ng_5); icr_ng_times[4] =1;
            ng_count_times[4] += 1;
        }
        else{ui->uart_status->setText("MSG_YYY"); console->putData(MSG_YYY); }

        //ui->uart_status->setText("MSG_Ng");
        //console->putData(MSG_Ng);
        ui->but_start->setEnabled(false);
        ui->func_group->setEnabled(false);
        //ui->all_test->setChecked(false);
        //ui->degree_0->setChecked(false);
        //ui->degree_90->setChecked(false);
        //ui->degree_180->setChecked(false);
        //ui->but_reset->setEnabled(true);
        ui->but_reset->setEnabled(false);
        ui->icr_time_sel->setEnabled(false);
        ui->voltage_Box->setEnabled(false);
        ui->voltage_dial->setEnabled(false);
        //ui->icr_time_sel->setEnabled(true);
        //ui->voltage_Box->setEnabled(true);
        //ui->voltage_dial->setEnabled(true);
    }
    else if((data[2] == '$') && (data[3] == 'f') && (data[4] == '0') && (data[5] == '8')) {

        if(icr_ng_times[0] != 0)    ui->icr_1->setStyleSheet("QLabel { background-color : red; color : blue; }");
        else                        ui->icr_1->setStyleSheet("QLabel { background-color : green; color : blue; }");
        if(icr_ng_times[1] != 0)    ui->icr_2->setStyleSheet("QLabel { background-color : red; color : blue; }");
        else                        ui->icr_2->setStyleSheet("QLabel { background-color : green; color : blue; }");
        if(icr_ng_times[2] != 0)    ui->icr_3->setStyleSheet("QLabel { background-color : red; color : blue; }");
        else                        ui->icr_3->setStyleSheet("QLabel { background-color : green; color : blue; }");
        if(icr_ng_times[3] != 0)    ui->icr_4->setStyleSheet("QLabel { background-color : red; color : blue; }");
        else                        ui->icr_4->setStyleSheet("QLabel { background-color : green; color : blue; }");
        if(icr_ng_times[4] != 0)    ui->icr_5->setStyleSheet("QLabel { background-color : red; color : blue; }");
        else                        ui->icr_5->setStyleSheet("QLabel { background-color : green; color : blue; }");

        for(int k=0; k<5; k++)
            icr_ng_times[k] = 0;
        ui->uart_status->setText("MSG_Finish");
        console->putData(MSG_Finish);

        /*
        data.clear();

                */

        int temp_value=0,value=0;
        QTime index(0,0,0);
        /*
        QByteArray byteArray;
        char a;
        char b;
        char c;
        char d;
        */
        QTime dieTime = QTime::currentTime().addSecs(600);
        while(QTime::currentTime() < dieTime)
        {
            ui->but_stop->setEnabled(true);
            temp_value = (index.secsTo(dieTime)) - (index.secsTo( QTime::currentTime()));

            if(temp_value != value)
            {
                value = temp_value;
                ui->count_down->setText(QString::number(value, 10));
                /*
                a = (value >> 24) & 0xFF;
                b = (value >> 16) & 0xFF;
                c = (value >> 8) & 0xFF;
                d = value & 0xFF;
                byteArray.append(a);
                byteArray.append(b);
                byteArray.append(c);
                byteArray.append(d);
                console->putData(byteArray);
                byteArray.clear();
                */
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

                if(reset_flag == 1)
                    break;
            }
        }

        if(reset_flag == 0)
            emit on_but_auto_released();


        reset_flag = 0;
        ui->but_stop->setEnabled(false);
        /*
            ui->func_group->setEnabled(true);
            ui->but_start->setEnabled(true);
            ui->but_reset->setEnabled(true);
            ui->icr_time_sel->setEnabled(true);
            ui->voltage_Box->setEnabled(true);
            ui->voltage_dial->setEnabled(true);
        */
    }
    else
        ui->uart_status->setText("Oops");

    data.clear();

    ui->icr1_ng->setText(QString::number(ng_count_times[0]));
    ui->icr2_ng->setText(QString::number(ng_count_times[1]));
    ui->icr3_ng->setText(QString::number(ng_count_times[2]));
    ui->icr4_ng->setText(QString::number(ng_count_times[3]));
    ui->icr5_ng->setText(QString::number(ng_count_times[4]));

    ui->icr1_ok->setText(QString::number(ok_count_times[0]));
    ui->icr2_ok->setText(QString::number(ok_count_times[1]));
    ui->icr3_ok->setText(QString::number(ok_count_times[2]));
    ui->icr4_ok->setText(QString::number(ok_count_times[3]));
    ui->icr5_ok->setText(QString::number(ok_count_times[4]));
}
//! [7]

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
//! [8]

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(openSerialPort()));
    connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialPort()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
    connect(ui->actionClear, SIGNAL(triggered()), console, SLOT(clear()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::on_but_start_released()
{
    QByteArray MSG_ButStart("$90");
    QByteArray MSG_IcrTime("$A0");
    QByteArray MSG_AllTest_CHK("$00");
    QByteArray MSG_0_degree_CHK("$01");
    QByteArray MSG_90_degree_CHK("$02");
    QByteArray MSG_180_degree_CHK("$03");
    QByteArray MSG_AnyLdo("$B0");

    int index=0;
    index = ui->icr_time_sel->currentIndex();
    switch(index)
    {
    case 0:                MSG_IcrTime[2]='0';                break;
    case 1:                MSG_IcrTime[2]='1';                break;
    case 2:                MSG_IcrTime[2]='2';                break;
    case 3:                MSG_IcrTime[2]='3';                break;
    case 4:                MSG_IcrTime[2]='4';                break;
    case 5:                MSG_IcrTime[2]='5';                break;
    case 6:                MSG_IcrTime[2]='6';                break;
    case 7:                MSG_IcrTime[2]='7';                break;
    case 8:                MSG_IcrTime[2]='8';                break;
    case 9:                MSG_IcrTime[2]='9';                break;
    default:                                                  break;
    }
    serial->write(MSG_IcrTime);
    ui->icr_time_sel->setEnabled(false);

    int ldo_voltage=0;
    ldo_voltage = ui->voltage_Box->value();
    switch(ldo_voltage)
    {
    case 3650: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='0'; break;  case 3600: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='1'; break;  case 3550: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='2'; break;
    case 3500: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='3'; break;  case 3450: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='4'; break;  case 3400: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='5'; break;
    case 3350: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='6'; break;  case 3300: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='7'; break;  case 3250: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='8'; break;
    case 3200: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='9'; break;  case 3150: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='A'; break;  case 3100: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='B'; break;
    case 3050: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='C'; break;  case 3000: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='D'; break;  case 2950: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='E'; break;
    case 2900: MSG_AnyLdo[1]='B'; MSG_AnyLdo[2]='F'; break;  case 2850: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='0'; break;  case 2800: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='1'; break;
    case 2750: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='2'; break;  case 2700: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='3'; break;  case 2650: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='4'; break;
    case 2600: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='5'; break;  case 2550: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='6'; break;  case 2500: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='7'; break;
    case 2450: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='8'; break;  case 2400: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='9'; break;  case 2350: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='A'; break;
    case 2300: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='B'; break;  case 2250: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='C'; break;  case 2200: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='D'; break;
    case 2150: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='E'; break;  case 2100: MSG_AnyLdo[1]='C'; MSG_AnyLdo[2]='F'; break;  case 2050: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='0'; break;
    case 2000: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='1'; break;  case 1950: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='2'; break;  case 1900: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='3'; break;
    case 1850: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='4'; break;  case 1800: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='5'; break;  case 1750: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='6'; break;
    case 1700: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='7'; break;  case 1650: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='8'; break;  case 1600: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='9'; break;
    case 1550: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='A'; break;  case 1500: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='B'; break;  case 1450: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='C'; break;
    case 1400: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='D'; break;  case 1350: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='E'; break;  case 1300: MSG_AnyLdo[1]='D'; MSG_AnyLdo[2]='F'; break;
    case 1250: MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='0'; break;  case 1200: MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='1'; break;  case 1150: MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='2'; break;
    case 1100: MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='3'; break;  case 1050: MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='4'; break;  case 1000: MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='5'; break;
    case 950 : MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='6'; break;  case 900 : MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='7'; break;  case 850 : MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='8'; break;
    case 800 : MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='9'; break;  case 750 : MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='A'; break;  case 700 : MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='B'; break;
    case 650 : MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='C'; break;  case 600 : MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='D'; break;  case 550 : MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='E'; break;
    case 500 : MSG_AnyLdo[1]='E'; MSG_AnyLdo[2]='F'; break;
    default: break;
    }
    serial->write(MSG_AnyLdo);
    ui->voltage_Box->setEnabled(false);
    ui->voltage_dial->setEnabled(false);

    if(ui->all_test->isChecked())
    {
        ui->but_reset->setEnabled(false); ui->icr_time_sel->setEnabled(false); ui->func_group->setEnabled(false); ui->voltage_Box->setEnabled(false); ui->voltage_dial->setEnabled(false);
        ui->but_start->setEnabled(false);
        serial->write(MSG_AllTest_CHK);
    }
    else if(ui->degree_0->isChecked())
    {
        ui->but_reset->setEnabled(false); ui->icr_time_sel->setEnabled(false); ui->func_group->setEnabled(false); ui->voltage_Box->setEnabled(false); ui->voltage_dial->setEnabled(false);
        ui->but_start->setEnabled(false);
        serial->write(MSG_0_degree_CHK);
    }
    else if(ui->degree_90->isChecked())
    {
        ui->but_reset->setEnabled(false); ui->icr_time_sel->setEnabled(false); ui->func_group->setEnabled(false); ui->voltage_Box->setEnabled(false); ui->voltage_dial->setEnabled(false);
        ui->but_start->setEnabled(false);
        serial->write(MSG_90_degree_CHK);
    }
    else if(ui->degree_180->isChecked())
    {
        ui->but_reset->setEnabled(false); ui->icr_time_sel->setEnabled(false); ui->func_group->setEnabled(false); ui->voltage_Box->setEnabled(false); ui->voltage_dial->setEnabled(false);
        ui->but_start->setEnabled(false);
        serial->write(MSG_180_degree_CHK);
    }
    else
    {
        serial->write(MSG_ButStart);
    }

    ui->icr_1->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_2->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_3->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_4->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_5->setStyleSheet("QLabel { background-color : gray; color : blue; }");

    for(int k=0; k<5; k++)
        icr_ng_times[k] = 0;
}

void MainWindow::on_but_reset_released()
{
    QByteArray MSG_ButReset("$91");

    for(int k=0; k<5; k++)
    {
        icr_ng_times[k] = 0;
    }

    ui->uart_status->setStyleSheet("background-color: rgb(0, 255, 0);font-size:60px;color:blue");

    ui->icr_1->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_2->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_3->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_4->setStyleSheet("QLabel { background-color : gray; color : blue; }");
    ui->icr_5->setStyleSheet("QLabel { background-color : gray; color : blue; }");

    ui->but_auto->setEnabled(false);
    ui->but_stop->setEnabled(false);
    ui->func_group->setEnabled(false);
    ui->all_test->setChecked(false);
    ui->degree_0->setChecked(false);
    ui->degree_90->setChecked(false);
    ui->degree_180->setChecked(false);
    serial->write(MSG_ButReset);
}

void MainWindow::on_all_test_clicked(bool checked)
{
    if(checked == true)
    {
        ui->degree_0->setChecked(false);
        ui->degree_90->setChecked(false);
        ui->degree_180->setChecked(false);
    }
}

void MainWindow::on_degree_0_clicked(bool checked)
{
    if(checked == true)
    {
        ui->all_test->setChecked(false);
        ui->degree_90->setChecked(false);
        ui->degree_180->setChecked(false);
    }
}

void MainWindow::on_degree_90_pressed()
{

}

void MainWindow::on_degree_90_clicked(bool checked)
{
    if(checked == true)
    {
        ui->all_test->setChecked(false);
        ui->degree_0->setChecked(false);
        ui->degree_180->setChecked(false);
    }
}

void MainWindow::on_degree_180_clicked(bool checked)
{
    if(checked == true)
    {
        ui->all_test->setChecked(false);
        ui->degree_0->setChecked(false);
        ui->degree_90->setChecked(false);
    }
}

void MainWindow::on_voltage_dial_valueChanged(int value)
{
    if(value == 1)
        ui->voltage_Box->setValue(500);
    else
        ui->voltage_Box->setValue(500+((value-1)*50));

}

void MainWindow::on_voltage_Box_valueChanged(int arg1)
{
    int dial_value = 0;

    dial_value = arg1 - 500;
    if(dial_value == 0)
        ui->voltage_dial->setValue(1);
    else
        ui->voltage_dial->setValue(1+(dial_value/50));
}

void MainWindow::on_but_auto_released()
{
    QByteArray MSG_AllTest_CHK("$00");
    ui->func_group->setEnabled(false);
    ui->all_test->setChecked(false);
    ui->degree_0->setChecked(false);
    ui->degree_90->setChecked(false);
    ui->degree_180->setChecked(false);
    ui->but_start->setEnabled(false);
    ui->but_reset->setEnabled(false);

    serial->write(MSG_AllTest_CHK);

    ui->but_auto->setEnabled(false);
}

void MainWindow::on_but_stop_released()
{
    ui->but_stop->setEnabled(false);
    ui->but_auto->setEnabled(true);
    ui->but_reset->setEnabled(true);

    reset_flag = 1;

    for(int k=0; k<5; k++)
    {
        ng_count_times[k] = 0;
        ok_count_times[k] = 0;
    }

    ui->icr1_ng->setText(QString::number(ng_count_times[0]));
    ui->icr2_ng->setText(QString::number(ng_count_times[1]));
    ui->icr3_ng->setText(QString::number(ng_count_times[2]));
    ui->icr4_ng->setText(QString::number(ng_count_times[3]));
    ui->icr5_ng->setText(QString::number(ng_count_times[4]));

    ui->icr1_ok->setText(QString::number(ok_count_times[0]));
    ui->icr2_ok->setText(QString::number(ok_count_times[1]));
    ui->icr3_ok->setText(QString::number(ok_count_times[2]));
    ui->icr4_ok->setText(QString::number(ok_count_times[3]));
    ui->icr5_ok->setText(QString::number(ok_count_times[4]));

    ui->count_down->setText(QString::number(0, 10));
}
