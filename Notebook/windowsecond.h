#ifndef WINDOWSECOND_H
#define WINDOWSECOND_H

#include <QDialog>

namespace Ui {
class WindowSecond;
}

class WindowSecond : public QDialog
{
    Q_OBJECT

public:
    explicit WindowSecond(QWidget *parent = nullptr);
    ~WindowSecond();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WindowSecond *ui;
};

#endif // WINDOWSECOND_H
