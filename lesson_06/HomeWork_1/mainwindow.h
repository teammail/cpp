#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_downButton_clicked();

  void on_rightButton_clicked();

  void on_leftButton_clicked();

  void on_upButton_clicked();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
