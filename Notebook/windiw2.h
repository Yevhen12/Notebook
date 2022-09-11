#ifndef WINDIW2_H
#define WINDIW2_H

#include <QDialog>

namespace Ui {
class windiw2;
}

class windiw2 : public QDialog
{
    Q_OBJECT

public:
    explicit windiw2(QWidget *parent = nullptr);
    ~windiw2();

private:
    Ui::windiw2 *ui;
};

#endif // WINDIW2_H
