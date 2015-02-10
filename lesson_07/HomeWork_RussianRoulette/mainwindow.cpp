#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  round(0),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // Очищаем лог игры
  ui->gameLog->clear();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::log(QString s)
{
  ui->gameLog->append(s);
}

void MainWindow::on_playButton_clicked()
{
  // Один раунд игры
  round++;
  log(QString("<b>Раунд %1:</b>").arg(round));

  // Ставка
  double bet = ui->betEdit->value();
  int N = ui->numberEdit->value();
  log(QString("Ваша ставка %1 на %2.").arg(bet).arg(N));

  // Крутим рулетку
  int num = (qrand() % 10 + 1);
  log(QString("Выпало: %1.").arg(num));

  // Пересчитываем баланс
  double balance = ui->balanceLabel->text().toDouble();
  double oldBalance = balance;
  if(num == N){
    balance += bet * 10;
    log(QString("Выйграли! Новый счёт: %1 + %2 = %3")
        .arg(oldBalance).arg(balance - oldBalance).arg(balance));
  } else {
    balance -= bet;
    log(QString("Проиграли! Новый счёт: %1 - %2 = %3")
        .arg(oldBalance).arg(oldBalance - balance).arg(balance));
  }
  ui->balanceLabel->setText(QString("%1").arg(balance,2));
}
