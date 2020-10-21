#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QDir>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void changeCurrentDir();
private:
    QTreeView* tree;
    QFileSystemModel* model;
    QWidget* widget;
    QLineEdit* line;
    QPushButton * findB;
};

#endif // MAINWINDOW_H
