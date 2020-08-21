#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include <QMainWindow>
#include<QMap>
#include<QDebug>

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
    void on_plainTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
    QMap<QString, QChar> map;
};

#endif // MAINWINDOW_H
