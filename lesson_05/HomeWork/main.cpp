#include <iostream>
#include <fstream> // Файловый ввод и вывод с помощью потоков
#include <map>

using namespace std;

int main()
{
  //ifstream dictFile("dict.txt");

  map <string, string> dict;
  /*while(!dictFile.eof()){
    string from, to;
    dictFile >> from >> to;
  }*/

  ifstream in("in.txt");
  ofstream out("out.txt");

  int wordCount = 0;
  while(!in.eof()){
    string s;
    in >> s;
    cout << (++wordCount) << ". " << s << endl;
  }

  in.close();
  out.close();

  return 0;
}
