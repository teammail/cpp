#include <iostream>
#include <fstream> // Файловый ввод и вывод с помощью потоков
#include <map>

using namespace std;

map <string, string> dict;

// Чтение словаря из файла
void readDictionary() {
  string dictFileName("dict.txt");
  ifstream dictFile(dictFileName);
  if (!dictFile.good()) {
    cout << "File \"" << dictFileName << "\" - not exists!" << endl;
  }
  while(!dictFile.eof()){
    string from, to;
    dictFile >> from >> to;
    dict[from] = to;
  }
  dictFile.close();
}

int main() {
  readDictionary();

  ifstream in("in.txt");
  ofstream out("out.txt");

  int wordCount = 0;
  while(!in.eof()) {
    string s;
    in >> s;
    cout << (++wordCount) << ". " << s << endl;
    out << dict[s] << " ";
  }

  in.close();
  out.close();

  return 0;
}
