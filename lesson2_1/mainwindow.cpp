#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map["RUB"] = QChar(0x20BD);
    map["COPY"] = QChar(0x00A9);
    map["PROMIL"] = QChar(0x2030);
    map["EUR"] = QChar(0x20AC);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plainTextEdit_textChanged()
{
    QString str = ui->plainTextEdit->toPlainText();
    int fnd = str.indexOf("#@");
    if(fnd != -1){
        int exeInd;
        for(auto it = map.begin(); it != map.end(); it++){
            exeInd = str.indexOf(it.key());
            if((exeInd != -1) && (exeInd - fnd == 2) && str[exeInd + it.key().length()] == '@'){

                str.replace(fnd, it.key().size() + 3, it.value());
//                str.append(it.value());
                ui->plainTextEdit->setPlainText(str);
            }
        }
    }
}
