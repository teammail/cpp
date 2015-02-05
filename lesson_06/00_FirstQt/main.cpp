#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  // Основное окно
  MainWindow w;
  // показываем окно
  w.show();

  // Запуск основного цикла обработки событий
  return a.exec();
}
