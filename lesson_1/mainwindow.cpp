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

void MainWindow::on_resultButton1_clicked()
{
    double a = ui->aValue->text().toDouble();
    double b = ui->bValue->text().toDouble();
    double c = ui->cValue->text().toDouble();
    double res1;
    double res2;
    double D;
    if(!a){
        res1 = (0 - c) / b;
        ui->x1->setText(QString::number(res1));
        ui->x2->setText("Уравнение не квадратное");
    }else{
        D = (b * b) - (4 * a * c);
        if(D < 0){
            ui->x1->setText("Нет корней.");
            ui->x2->setText("Нет корней.");
        }
        else{
            res1 = (-b - qSqrt(D)) / (2 * a);
            res2 = (-b + qSqrt(D)) / (2 * a);
            ui->x1->setText(QString::number(res1));
            ui->x2->setText(QString::number(res2));
        }
    }
}

void MainWindow::on_resultButton2_clicked()
{
    double a = ui->aVal2->text().toDouble();
    double b = ui->bVal2->text().toDouble();
    double Y = ui->yVal2->text().toDouble();
    double res;
    if(ui->radioRad2->isChecked()){
        Y = 180 / M_PI * Y;
    }
    res = qSqrt(qPow(a, 2) + qPow(b, 2) - (2 * a * b * qCos(Y)));
    ui->labelResult2->setText(QString::number(res));

}

void MainWindow::on_addTextButton3_clicked()
{
    QString str = ui->firstPlainTextEdit3->toPlainText();
    ui->seconPlainTextEdit3->appendPlainText(str);
}


void MainWindow::on_replaceTextButton3_clicked()
{
    QString str = ui->firstPlainTextEdit3->toPlainText();
    ui->seconPlainTextEdit3->setPlainText(str);
}

void MainWindow::on_setHtmlButton3_clicked()
{
    QString str = ui->firstPlainTextEdit3->toPlainText();
    ui->seconPlainTextEdit3->appendHtml(str);
}
