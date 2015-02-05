#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug> // Вывод сообщений в консоль отладки

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

// Слот
void MainWindow::on_pushButton_clicked()
{
  qDebug() << "pushButton_clicked()";
}
