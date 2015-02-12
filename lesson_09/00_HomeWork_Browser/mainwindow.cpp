#include <QDebug> // Вывод отладочных сообщений в консоль
#include <QMessageBox> // Вывод окон с сообщениями пользователю
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
  // При нажатии на кнопку Go переходим на адрес
  ui->webView->setUrl(ui->urlEdit->text());
}

// Добавление адреса сайта в закладки
void MainWindow::on_toolButton_clicked() {
  // Создаём новую кнопку
  QPushButton *button = new QPushButton(this);
  button->setText(ui->urlEdit->text());

  // При нажатии на кнопку переходим на адрес
  connect(button, SIGNAL(clicked()), this, SLOT(on_goToHistory_clicked()));

  // Добавляем на панель
  ui->historyTools->addWidget(button);
}

void MainWindow::on_goToHistory_clicked() {
  // TODO: реализовать
  // Кто отправил сигнал?
  QPushButton *button = (QPushButton *)QObject::sender();
  if(button == NULL){
    qDebug() << "Должны быть только объекты QPushButton";
    return;
  }

  QString url = button->text();
  // Выводим URL для отладки
  qDebug() << "URL:" << url;
  ui->urlEdit->setText(url);
  ui->webView->setUrl(url);
}

void MainWindow::on_webView_urlChanged(const QUrl &url)
{
  ui->urlEdit->setText(url.toString());
}
