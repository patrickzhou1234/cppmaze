#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int px = 0, py = 0;

void CopyMaze(vector <vector<char>> &vec, string &readfile) {
  fstream read(readfile);
  string line;
  int counter = 0;
  while (getline(read, line)) {
    vector <char> innerVec;
    for (int i = 0; i < line.length(); i++) {
      if (line[i] == 'X') {
        px = i;
        py = counter;
      }
      innerVec.push_back(line[i]);
    }
    vec.push_back(innerVec);
    counter++;
  }
  read.close();
}

void PrintFunc(vector <vector<char>> &vec) {
  system("clear");
  for (auto &row : vec) {
    for (auto &col : row) {
      cout << col << ' ';
    }
    cout << endl;
  }
}

bool CheckInput(char &inputkey, vector <vector<char>> &vec) {
  int xdir = 0, ydir = 0;
  switch(inputkey) {
    case 'w':
    ydir = -1;
    break;
    case 'a':
    xdir = -1;
    break;
    case 's':
    ydir = 1;
    break;
    case 'd':
    xdir = 1;
    break;
    default:
    return false;
  }
  if (vec[py+ydir][px+xdir] == 'O') {
    system("clear");
    cout << "You Won!" << endl;
    return true;
  }
  if (!(vec[py+ydir][px+xdir] == '#')) {
    vec[py+ydir][px+xdir] = 'X';
    vec[py][px] = ' ';
    py += ydir;
    px += xdir;
  }
  return false;
}

int main() {
  int levelcounter = -1;
  string arr[] = {"input.txt", "input1.txt"};
  while (true) {
    levelcounter++;
    if (levelcounter == 2) {
      cout << "No more levels" << endl;
      break;
    }
    vector <vector<char>> vec;
    CopyMaze(vec, arr[levelcounter]);
    char inputkey = ' ';
    do {
      if (CheckInput(inputkey, vec)) {
        break;
      }
      PrintFunc(vec);
    } while (cin >> inputkey);
    cout << "Do you wish to continue?" << endl;
    char yn;
    cin >> yn;
    if (yn == 'y') {
      continue;
    } else {
      cout << "ok" << endl;
      break;
    }
  }
}
