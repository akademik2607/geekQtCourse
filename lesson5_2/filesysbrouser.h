#ifndef FILESYSBROUSER_H
#define FILESYSBROUSER_H

#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QDir>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollBar>
#include <QGridLayout>

class FileSysBrouser : public QWidget
{
    Q_OBJECT
public:
    explicit FileSysBrouser(QWidget *parent = nullptr);

private:
    QTreeView* tree;
    QFileSystemModel* model;

    QLineEdit* line;
    QPushButton * findB;

signals:

public slots:
    void changeCurrentDir();
};

#endif // FILESYSBROUSER_H
