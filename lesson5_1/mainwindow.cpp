#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->rusButton, &QRadioButton::toggled, this, &MainWindow::changeOfLang);
//    connect(ui->engButton, &QRadioButton::toggled, this, &MainWindow::changeOfLang); //Соединил с 1 кнопкой, чтобы не дублировать вызовы слота
    connect(this, SIGNAL(updateSignal()), this, SLOT(update()));

    //Светлый стиль
    setStyleSheet("QMainWindow{background-color: #131313;}"
                  "QPlainTextEdit{background-color: black; color: white;}"
                  "QRadioButton{color: green}");

    themColors.insert(QString("Dark"), QString("QMainWindow{background-color: #131313;}"
                               "QPlainTextEdit{background-color: black; color: white;}"
                               "QRadioButton{color: green}"));

    setStyleSheet("QMainWindow{background-color: #FFFFE0;}"
                  "QPlainTextEdit{background-color: white; color: black;}"
                  "QRadioButton{color: black}");

    themColors.insert(QString("Light"), QString("QMainWindow{background-color: #FFFFE0;}"
                                                         "QPlainTextEdit{background-color: white; color: black;}"
                                                         "QRadioButton{color: black}"));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFileButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName();
    qDebug() << fileName;
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);

        ui->plainTextEdit->setPlainText(stream.readAll());
    }
}

void MainWindow::on_saveFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName();
    qDebug() << fileName;
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)){
        QString str = ui->plainTextEdit->toPlainText();
        QTextStream stream(&file);
        stream << str;


    }
}

void MainWindow::on_descriptionButton_clicked()
{
    QFile file(":/text/description.txt");
    if(!file.open(QIODevice::ReadOnly)) return;
    QTextStream stream(&file);
    QString str;
    str = stream.readAll();
    QMessageBox message(QMessageBox::Icon::Information, tr("Описание"), str);
    message.exec();


}

void MainWindow::changeOfLang()
{
    if(ui->rusButton->isChecked()){
        qApp->removeTranslator(&translator);
    }
    else{
        translator.load("Qt_eng");
        qApp->installTranslator(&translator);

    }

    ui->retranslateUi(this);


}


void MainWindow::on_lightColorButton_toggled(bool checked)
{
    if(checked == true){
        setStyleSheet(themColors[QString("Light")]);

    }
    else{
        setStyleSheet(themColors[QString("Dark")]);
    }
    ui->retranslateUi(this);
}
