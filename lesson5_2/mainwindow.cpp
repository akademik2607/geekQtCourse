#include "mainwindow.h"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(0, 0, 800, 600);
    brouser = new FileSysBrouser(this);
    setCentralWidget(brouser);
}

MainWindow::~MainWindow()
{

}


