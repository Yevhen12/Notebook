#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowsecond.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    centralWidget()->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(centralWidget(), SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(CtxMenu(const QPoint&)));

    QShortcut *keyCtrlN = new QShortcut(this);
    keyCtrlN->setKey(Qt::CTRL | Qt::Key_N);
    connect(keyCtrlN, SIGNAL(activated()), this, SLOT(shortcutCtrlN()));

    QShortcut *keyCtrlO = new QShortcut(this);
    keyCtrlO->setKey(Qt::CTRL | Qt::Key_O);
    connect(keyCtrlO, SIGNAL(activated()), this, SLOT(shortcutCtrlO()));

    QShortcut *keyCtrlS = new QShortcut(this);
    keyCtrlS->setKey(Qt::CTRL | Qt::Key_S);
    connect(keyCtrlS, SIGNAL(activated()), this, SLOT(shortcutCtrlS()));

    QShortcut *keyCtrlShiftS = new QShortcut(this);
    keyCtrlShiftS->setKey(Qt::CTRL | Qt::SHIFT | Qt::Key_S);
    connect(keyCtrlShiftS, SIGNAL(activated()), this, SLOT(shortcutCtrlShiftS()));

    QShortcut *keyCtrlX = new QShortcut(this);
    keyCtrlX->setKey(Qt::CTRL | Qt::Key_X);
    connect(keyCtrlX, SIGNAL(activated()), this, SLOT(shortcutCtrlX()));

    QShortcut *keyCtrlC = new QShortcut(this);
    keyCtrlC->setKey(Qt::CTRL | Qt::Key_C);
    connect(keyCtrlC, SIGNAL(activated()), this, SLOT(shortcutCtrlC()));

    QShortcut *keyCtrlA = new QShortcut(this);
    keyCtrlA->setKey(Qt::CTRL | Qt::Key_A);
    connect(keyCtrlA, SIGNAL(activated()), this, SLOT(shortcutCtrlA()));

    QShortcut *keyCtrlV = new QShortcut(this);
    keyCtrlV->setKey(Qt::CTRL | Qt::Key_V);
    connect(keyCtrlV, SIGNAL(activated()), this, SLOT(shortcutCtrlV()));

    QShortcut *keyCtrlZ = new QShortcut(this);
    keyCtrlZ->setKey(Qt::CTRL | Qt::Key_Z);
    connect(keyCtrlZ, SIGNAL(activated()), this, SLOT(shortcutCtrlZ()));

    QShortcut *keyCtrlShiftZ = new QShortcut(this);
    keyCtrlShiftZ->setKey(Qt::CTRL | Qt::SHIFT | Qt::Key_Z);
    connect(keyCtrlShiftZ, SIGNAL(activated()), this, SLOT(shortcutCtrlShiftZ()));

    QShortcut *keyAlt = new QShortcut(this);
    keyAlt->setKey(Qt::ALT);
    connect(keyAlt, SIGNAL(activated()), this, SLOT(shortcutAlt()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{
    LYCurrentText = ui->textEdit->toPlainText();
    if(LYCurrentText != LYSavedText){
        setWindowTitle("*Notepad");
    }
}


void MainWindow::CtxMenu(const QPoint& pos){
    QPoint globalPos = centralWidget()->mapToGlobal(pos);

    QMenu myMenu;

    myMenu.addAction("Copy", this, SLOT(on_action_1()));
    myMenu.addAction("Paste", this, SLOT(on_action_2()));
    myMenu.addAction("Cut", this, SLOT(on_action_3()));
    myMenu.addAction("Redo", this, SLOT(on_action_4()));
    myMenu.addAction("Undo", this, SLOT(on_action_5()));
    myMenu.exec(globalPos);
}

void MainWindow::on_action_1()
{
    on_actionCopy_triggered();
}
void MainWindow::on_action_2()
{
    on_actionPaste_triggered();
}
void MainWindow::on_action_3()
{
    on_actionCut_triggered();
}
void MainWindow::on_action_4()
{
    on_actionRedo_triggered();
}
void MainWindow::on_action_5()
{
    on_actionUndo_triggered();
}


void MainWindow::on_actionNew_triggered()
{

    if(LYSavedText != LYCurrentText) {
        QMessageBox LYSaveMessage;
        LYSaveMessage.setText("U dont save app.  Are u sure that u want to close it?    ");
        LYSaveMessage.setWindowTitle("Helper");

        QAbstractButton *LYSave = (QAbstractButton*)LYSaveMessage.addButton("Save", QMessageBox::ActionRole);
        QAbstractButton *LYRejectSave = (QAbstractButton*)LYSaveMessage.addButton("Dont save", QMessageBox::NoRole);
        QAbstractButton *LYCancel = (QAbstractButton*)LYSaveMessage.addButton(QAbstractButton::tr("Cancel"), QMessageBox::YesRole);

        LYSaveMessage.exec();

       if(LYSaveMessage.clickedButton() == LYSave) {
           on_actionSave_triggered();
       } else if (LYSaveMessage.clickedButton() == LYRejectSave) {
           LYSaveMessage.close();
       } else {
           LYSaveMessage.close();
           return;
       }
    }

    LYFileMain = "";
    ui->textEdit->setPlainText("");
}


void MainWindow::on_actionOpen_triggered()
{
    if(LYSavedText != LYCurrentText) {
        QMessageBox LYSaveMessage;
        LYSaveMessage.setText("U dont save app.  Are u sure that u want to close it?    ");
        LYSaveMessage.setWindowTitle("Helper");

        QAbstractButton *LYSave = (QAbstractButton*)LYSaveMessage.addButton("Save", QMessageBox::ActionRole);
        QAbstractButton *LYRejectSave = (QAbstractButton*)LYSaveMessage.addButton("Dont save", QMessageBox::NoRole);
        QAbstractButton *LYCancel = (QAbstractButton*)LYSaveMessage.addButton(QAbstractButton::tr("Cancel"), QMessageBox::YesRole);

        LYSaveMessage.exec();

       if(LYSaveMessage.clickedButton() == LYSave) {
           on_actionSave_triggered();
       } else if (LYSaveMessage.clickedButton() == LYRejectSave) {
           LYSaveMessage.close();
       } else {
           LYSaveMessage.close();
           return;
       }
    }

    QString LYFile;
    QString textFile;


    LYFile = QFileDialog::getOpenFileName(this, "Open file");

    if (!LYFile.isNull()) {
        QFile sFile(LYFile);

        if(sFile.open(QFile::ReadOnly | QFile::Text)) {
             LYFileMain = LYFile;
             QTextStream sFileIn(&sFile);
             ui->textEdit->setText(sFileIn.readAll());

             sFile.close();

        } else {
            QMessageBox::warning(this, "...", "Error");
            return;
        }
    }

}


void MainWindow::on_actionSave_triggered()
{

        QFile sFile(LYFileMain);

        if(LYFileMain == "") {
            on_actionSave_as_triggered();
        } else {
            if(sFile.open(QFile::WriteOnly | QFile::Text)) {
                 QTextStream sFileOut(&sFile);
                 sFileOut << ui->textEdit->toPlainText();
                 LYSavedText = ui->textEdit->toPlainText();
                 setWindowTitle("Notepad");
                 sFile.close();
            } else {
                QMessageBox::warning(this, "Error", "Error!!!");
                return;
            }
        }
}


void MainWindow::on_actionSave_as_triggered()
{

    QString LYFile;

    LYFile = QFileDialog::getSaveFileName(this, "Save file");

    if (!LYFile.isNull()) {
        QFile sFile(LYFile);

        if(sFile.open(QFile::WriteOnly | QFile::Text)) {
             LYFileMain = LYFile;
             QTextStream sFileOut(&sFile);
             sFileOut << ui->textEdit->toPlainText();
             LYSavedText = ui->textEdit->toPlainText();
             setWindowTitle("Notepad");
             sFile.close();

        } else {
            QMessageBox::warning(this, "...", "Error");
            return;
        }
    }

}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox::information(this, "Info", "Some information about us");
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionSelectAll_triggered()
{
    ui->textEdit->selectAll();
}


void MainWindow::on_actionExit_triggered()
{

    QApplication::closeAllWindows();


}

void MainWindow::closeEvent(QCloseEvent *event){

    if(LYSavedText != LYCurrentText){
        event->ignore();

        QMessageBox LYSaveMessage;
        LYSaveMessage.setText("U dont save app.  Are u sure that u want to close it?    ");
        LYSaveMessage.setWindowTitle("Helper");

        QAbstractButton *LYSave = (QAbstractButton*)LYSaveMessage.addButton("Save", QMessageBox::ActionRole);
        QAbstractButton *LYRejectSave = (QAbstractButton*)LYSaveMessage.addButton("Dont save", QMessageBox::NoRole);
        QAbstractButton *LYCancel = (QAbstractButton*)LYSaveMessage.addButton(QAbstractButton::tr("Cancel"), QMessageBox::YesRole);

        LYSaveMessage.exec();

       if(LYSaveMessage.clickedButton() == LYSave) {
           on_actionSave_triggered();
       } else if (LYSaveMessage.clickedButton() == LYRejectSave) {
             event->accept();
       } else {
            event->ignore();
       }
    }

}


void MainWindow::shortcutCtrlN() {
    on_actionNew_triggered();
}

void MainWindow::shortcutCtrlO() {
    on_actionOpen_triggered();
}

void MainWindow::shortcutCtrlS() {
    on_actionSave_triggered();
}

void MainWindow::shortcutCtrlShiftS() {
    on_actionSave_as_triggered();
}

void MainWindow::shortcutCtrlX() {
    on_actionCut_triggered();
}

void MainWindow::shortcutCtrlC() {
    on_actionCopy_triggered();
}

void MainWindow::shortcutCtrlA() {
    on_actionSelectAll_triggered();
}

void MainWindow::shortcutCtrlV() {
    on_actionPaste_triggered();
}

void MainWindow::shortcutCtrlZ() {
    on_actionUndo_triggered();
}

void MainWindow::shortcutCtrlShiftZ() {
    on_actionRedo_triggered();
}

void MainWindow::shortcutAlt(){
    on_actionSelectAll_triggered();
}





