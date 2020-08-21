#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_getWhetherButton_clicked();

    void on_questionButton_clicked();

    void on_getCurrencyButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
