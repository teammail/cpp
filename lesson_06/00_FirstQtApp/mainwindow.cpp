#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h" // Подключаю вторую форму
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->manualSignalSlotButton, SIGNAL(clicked()),
          this, SLOT(close()));
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

void MainWindow::on_closeButton_clicked()
{
   qDebug() << "on_closeButton_clicked()";
}

void MainWindow::on_concatButton_clicked()
{
   qDebug() << ui->lineEdit_1->text();
   qDebug() << ui->lineEdit_2->text();

   ui->resEdit->setText(ui->lineEdit_1->text() +
                        ui->lineEdit_2->text());
}
