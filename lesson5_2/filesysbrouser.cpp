#include "filesysbrouser.h"

FileSysBrouser::FileSysBrouser(QWidget *parent) : QWidget(parent)
{
    setGeometry(0, 0, 800, 600);

    line = new QLineEdit(this);
    findB = new QPushButton(QString("Поиск"), this);
    tree = new QTreeView(this);
    tree->setGeometry(0, 0, 2000, 2000);
    tree->setHeaderHidden(true);

    model = new QFileSystemModel(this);

    model->setRootPath(QDir::rootPath());

    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::rootPath()));
    tree->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    tree->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    tree->setVerticalScrollBar(new QScrollBar(this));
    tree->setAutoScroll(true);

    tree->setRootIsDecorated(false);
    QGridLayout * layout = new QGridLayout(this);
    layout->addWidget(line, 0, 0, 1, 1);
    layout->addWidget(findB, 0, 1, 1, 1);
    layout->addWidget(tree, 1, 0, 3, 3);
    setLayout(layout);


    connect(findB, &QPushButton::clicked , this, &FileSysBrouser::changeCurrentDir);
}

void FileSysBrouser::changeCurrentDir()
{
   QString str = line->text();
   QModelIndex index = model->setRootPath(str);
   tree->setRootIndex(index);
}
