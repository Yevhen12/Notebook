#include "windowsecond.h"
#include "ui_windowsecond.h"
#include "mainwindow.h"

WindowSecond::WindowSecond(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowSecond)
{
    ui->setupUi(this);
}

WindowSecond::~WindowSecond()
{
    delete ui;
}

void WindowSecond::on_pushButton_clicked()
{
//    MainWindow *saveBtn = new MainWindow();
//    saveBtn->setAttribute(Qt::)
}

