#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <QAbstractButton>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();





private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_as_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();
    void on_actionHelp_triggered();
    void on_actionRedo_triggered();
    void on_actionUndo_triggered();
    void on_actionSelectAll_triggered();
    void on_textEdit_textChanged();
    void on_actionExit_triggered();
    void closeEvent(QCloseEvent *event);




    void shortcutCtrlN();
    void shortcutCtrlO();
    void shortcutCtrlS();
    void shortcutCtrlShiftS();
    void shortcutCtrlX();
    void shortcutCtrlC();
    void shortcutCtrlA();
    void shortcutCtrlV();
    void shortcutCtrlZ();
    void shortcutCtrlShiftZ();
    void shortcutAlt();


    void CtxMenu(const QPoint& pos);
    void on_action_1();
    void on_action_2();
    void on_action_3();
    void on_action_4();
    void on_action_5();



private:
    Ui::MainWindow *ui;
    QString LYFileMain = "";
    QString LYCurrentText = "";
    QString LYSavedText = "";



    QShortcut *keyCtrlO;
    QShortcut *keyCtrlS;
    QShortcut *keyCtrlShiftN;
    QShortcut *keyCtrlX;
    QShortcut *keyCtrlC;
    QShortcut *keyCtrlA;
    QShortcut *keyCtrlV;
    QShortcut *keyCtrlZ;
    QShortcut *keyCtrlShiftZ;
    QShortcut *keyAlt;
};
#endif // MAINWINDOW_H
