#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_tree()
{
ui->textEdit->setText(tree.dum());
}


void MainWindow::on_add_clicked()
{
    tree.insert("rand",qrand());
    show_tree();
}


void MainWindow::on_delete_2_clicked()
{
    tree.erase(ui->key_le->text().toInt());
    show_tree();
}


void MainWindow::on_make_balanced_clicked()
{
    tree.make_balanced();
    show_tree();
}


void MainWindow::on_show_bykey_clicked()
{
    ui->data_le->setText(tree.find(ui->key_le->text().toInt()));
}


void MainWindow::on_make_balanced_2_clicked()
{
    ui->data_le->setText(QString::number(tree.count_symbols()));
}


void MainWindow::on_add_2_clicked()
{
    tree.insert(ui->lineEdit->text(),ui->lineEdit_2->text().toInt());
    show_tree();
}

