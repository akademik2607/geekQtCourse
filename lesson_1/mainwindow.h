#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmath.h>

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
    void on_resultButton1_clicked();

    void on_resultButton2_clicked();

    void on_addTextButton3_clicked();

    void on_replaceTextButton3_clicked();

    void on_setHtmlButton3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
