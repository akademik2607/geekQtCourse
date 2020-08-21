#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStandardItemModel>
#include <QDebug>
#include <iostream>

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
    void on_changeNameButton_clicked();

    void on_addLengButton_clicked();

    void on_delLengButton_clicked();

    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_modelCounterButton_clicked();

    void on_modelColumnsButton_clicked();



    void on_viewModeBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;
};

#endif // MAINWINDOW_H
