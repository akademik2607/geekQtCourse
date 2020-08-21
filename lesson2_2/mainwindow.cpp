#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList* strings = new QStringList();
    strings->append("C++");
    strings->append("Python");
    strings->append("Java");
    strings->append("C#");
    strings->append("PHP");
    strings->append("JavaScript");
    model = new QStandardItemModel();
    model->appendRow(new QStandardItem(QIcon("cplusplus.jpg"), QString("C++")));
    model->appendRow(new QStandardItem(QIcon("python.jpg"), QString("Python")));
    model->appendRow(new QStandardItem(QIcon("java.jpg"), QString("Java")));
    model->appendRow(new QStandardItem(QIcon("cSharp.png"), QString("C#")));
    model->appendRow(new QStandardItem(QIcon("php.png"), QString("PHP")));
    model->appendRow(new QStandardItem(QIcon("javascript.jpg"), QString("JavaScript")));


    ui->listView->setModel(model);
    ui->listView->setMovement(QListView::Movement::Free);
    ui->listView->setLayoutMode(QListView::LayoutMode::SinglePass);

    ui->listView->setDefaultDropAction(Qt::DropAction::MoveAction);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_changeNameButton_clicked()
{
    QModelIndex index = ui->listView->currentIndex();


}

void MainWindow::on_addLengButton_clicked()
{
    QString str = ui->addLengLine->text();
    if(str.isEmpty()) return;
    model->appendRow(new QStandardItem(QIcon("cplusplus.jpg"), QString(str)));
}

void MainWindow::on_delLengButton_clicked()
{
    QModelIndex ind = ui->listView->currentIndex();
    model->removeRow(ind.row());
}

void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
{
   qDebug() << model->rowCount();

}

void MainWindow::on_modelCounterButton_clicked()
{
    int count = model->rowCount();
    ui->modelItemCounter->setText(QString::number(count));
}

void MainWindow::on_modelColumnsButton_clicked()
{
    int count = model->columnCount();
    ui->modelItemCounter->setText(QString::number(count));
}



void MainWindow::on_viewModeBox_stateChanged(int arg1)
{
    if(ui->viewModeBox->isChecked()){
        ui->listView->setViewMode(QListView::ViewMode::IconMode);
        ui->listView->setDefaultDropAction(Qt::DropAction::TargetMoveAction);
    }
    else{
        ui->listView->setViewMode(QListView::ViewMode::ListMode);
        ui->listView->setDefaultDropAction(Qt::DropAction::MoveAction);
    }

}
