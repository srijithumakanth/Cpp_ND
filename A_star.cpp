#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};

vector<State> ParseLine(string line) {
    istringstream my_stream(line);
    int n;
    char c;
    vector<State> row;
    while (my_stream >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

vector<vector<State>> Search(vector<vector<State>> grid, int start[2], int goal[2])
{
  cout << "No, Path Found! \n";
  return {}; // Do I have to define a return type here?
}

string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
  }
}

void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

int main() {
  // Initizialize 
  int init[2] = {0,0};
  int goal[2] = {4,5};

  // Read the grid file and parse the content
  auto board = ReadBoardFile("board_1.txt");
  
  // Search the grid
  auto solution = Search(board, init, goal);
  
  // Print solution to the terminal
  PrintBoard(solution);
}