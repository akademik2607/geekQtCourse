#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{

    if(event->key() != Qt::Key_Return) return;

    QString str;
    str = ui->lineEdit->text();
    if(str.isEmpty()) return;
    setWindowTitle(str);

}
