#include <string>
#include <iostream>
#include <fstream>

#include <QtGui>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PWM_0 "/sys/class/leds/led-pwm0/brightness"
#define PWM_1 "/sys/class/leds/led-pwm1/brightness"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

static bool led(const char *dev, string& brightness)
{
    if ( "" == brightness) {
        ifstream ifs(dev);
        if (!ifs) {
            return false;
        }
        ifs >> brightness;
    } else {
        ofstream ofs(dev);
        if (!ofs) {
            return false;
        }
        ofs << brightness;
    }
    return true;
}

static void toggleLed(const char *dev)
{
    string b("");
    led(dev, b);
    if ("0" == b) {
        b = "127";
    } else {
        b = "0";
    }
    led(dev, b);
}

void MainWindow::on_pushButton_1_clicked()
{
    toggleLed(PWM_0);
}

void MainWindow::on_pushButton_2_clicked()
{
    toggleLed(PWM_1);
}

void MainWindow::on_pushButton_3_clicked()
{
    qApp->quit();
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::about(this, tr("About YY"),
                       tr("<h2>YY 1.0</h2>"
                          "<p>Copy right &copy; 2011 YuanYing Tech. Inc."));
}
