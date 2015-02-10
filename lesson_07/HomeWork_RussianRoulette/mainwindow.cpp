#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  round(0)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_playButton_clicked()
{
  // Один раунд игры
  round++;
  ui->gameLog->append(QString("<p><b>Раунд %1:</b></p>").arg(round));

  // Ставка
  double bet = ui->betEdit->value();
  int N = ui->numberEdit->value();
  ui->gameLog->append(QString("<p>Ваша ставка %1 на %2.</p>").arg(bet).arg(N));

  // Крутим рулетку
  int num = (qrand() % 10 + 1);
  ui->gameLog->append(QString("<p>Выпало: %1.</p>").arg(num));

  // Пересчитываем баланс
  double balance = ui->balanceLabel->text().toDouble();
  double oldBalance = balance;
  if(num == N){
    balance += bet * 10;
    ui->gameLog->append(QString("<p>Выйграли! Новый счёт: %1 + %2 = %3</p>")
                        .arg(oldBalance).arg(balance - oldBalance).arg(balance));
  } else {
    balance -= bet;
    ui->gameLog->append(QString("<p>Проиграли! Новый счёт: %1 - %2 = %3</p>")
                        .arg(oldBalance).arg(oldBalance - balance).arg(balance));
  }
  ui->balanceLabel->setText(QString("%1").arg(balance,2));
}
