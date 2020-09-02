#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QRadioButton>
#include <QTranslator>
#include <QApplication>

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
    void on_openFileButton_clicked();

    void on_saveFileButton_clicked();

    void on_descriptionButton_clicked();

    void changeOfLang();


private:
    Ui::MainWindow *ui;
    QRadioButton* rusButton;
    QRadioButton* engButton;
    QTranslator translator;

};

#endif // MAINWINDOW_H
