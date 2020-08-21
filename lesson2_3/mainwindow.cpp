#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList list, columnsName;
    list << "1" << "Tom" << "001.125.125.001" << "00-AB-CD-EF-11-22";
    columnsName << "№" << "name" << "ip" << "mac";

    qDebug() << columnsName;
    int columnCount = 4;
    int rowCount = 1;
    ui->tableWidget->setColumnCount(columnCount);
    ui->tableWidget->setRowCount(rowCount);



    ui->tableWidget->setHorizontalHeaderLabels(columnsName);
    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        auto item = new QTableWidgetItem(list.at(i));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(0, i, item);

    }
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->setColumnWidth(3, 150);

    ui->lineEdit_3->setInputMask("009.009.009.009;_");
    ui->lineEdit_4->setInputMask("HH:HH:HH:HH:HH:HH;_");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_changeColorButton_clicked()
{
    int curRow = ui->tableWidget->currentRow();
    ui->tableWidget->setAlternatingRowColors(true);
    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        auto item = ui->tableWidget->item(curRow, i);
        item->setBackgroundColor(QColor(120, 20, 20));
    }
}

void MainWindow::on_pushButton_clicked()
{
    QStringList list;
    list << ui->lineEdit_1->text() << ui->lineEdit_2->text() << ui->lineEdit_3->text() << ui->lineEdit_4->text();
    int rowCount = ui->tableWidget->rowCount() + 1;
    ui->tableWidget->setRowCount(rowCount);

    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        auto item = new QTableWidgetItem(list.at(i));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(rowCount - 1, i, item);
    }
}
