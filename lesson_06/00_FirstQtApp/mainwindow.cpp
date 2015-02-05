#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h" // Подключаю вторую форму

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  Dialog *dialog = new Dialog(this);
  dialog->show();
}
