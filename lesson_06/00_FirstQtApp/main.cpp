#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <iostream>

using namespace std;

// argc - количество аргументов
// argv - параметры командной строки
int main(int argc, char *argv[])
{
  cout << "argc: " << argc << endl;
  for(int i = 0; i < argc; ++i)
    cout << argv[i] << endl;

  // Обработка сигналов
  // Связь сигнал -> слот
  QApplication a(argc, argv);

  // Создаём основное окно
  MainWindow w;
  // Показываем основное окно
  w.show();

  cout << "Starting..." << endl;

  // Запуск основного цикла обработки событий
  int res = a.exec();

  cout << "Closing... res = " << res << endl;
  return res;
}
