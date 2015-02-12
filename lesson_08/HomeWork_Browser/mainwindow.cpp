#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_goButton_clicked()
{
  ui->webView->setUrl(ui->urlEdit->text());
}

void MainWindow::on_toolButton_clicked() {
  // Создаём новую кнопку
  QPushButton *button = new QPushButton(this);
  button->setText(ui->urlEdit->text());

  connect(button, SIGNAL(clicked()), this, SLOT(on_goToHistory_clicked()));

  // Добавляем на панель
  ui->historyTools->addWidget(button);
}

void MainWindow::on_goToHistory_clicked() {
  // Кто отправил сигнал?
  QPushButton *button = (QPushButton *)QObject::sender();
  QString url = button->text();
  ui->urlEdit->setText(url);
  ui->webView->setUrl(url);
}
