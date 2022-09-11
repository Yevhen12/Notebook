#include "windiw2.h"
#include "ui_windiw2.h"

windiw2::windiw2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windiw2)
{
    ui->setupUi(this);
}

windiw2::~windiw2()
{
    delete ui;
}
