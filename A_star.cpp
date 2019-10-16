#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // For sorting.
using std::abs;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

enum class State
{
  kEmpty,
  kObstacle,
  kClosed,
  kPath
};

vector<State> ParseLine(string line)
{
  istringstream my_stream(line);
  int n;
  char c;
  vector<State> row;
  while (my_stream >> n >> c && c == ',')
  {
    if (n == 0)
    {
      row.push_back(State::kEmpty);
    }
    else
    {
      row.push_back(State::kObstacle);
    }
  }
  return row;
}

vector<vector<State>> ReadBoardFile(string path)
{
  ifstream myfile(path);
  vector<vector<State>> board{};
  if (myfile)
  {
    string line;
    while (getline(myfile, line))
    {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

// Function to compare the f-value of two nodes.
bool Compare(vector<int> n1, vector<int> n2)
{
  // f = g + h
  int f1 = n1[2] + n1[3];
  int f2 = n2[2] + n2[3];
  return f1 > f2;
}

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v)
{
  sort(v->begin(), v->end(), Compare);
}

int Heuristic(int x1, int y1, int x2, int y2)
{
  // Calculate the Manhattan distance between the current and the goal coordinates.
  return abs(x2 - x1) + abs(y2 - y1);
}

// CheckValidCell function to check that the cell is on the grid and not an obstacle (i.e. equals kEmpty).
bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
{
  bool on_grid_x = (x >= 0 && x < grid.size());
  bool on_grid_y = (y >= 0 && y < grid[0].size());
  if (on_grid_x && on_grid_y)
    return grid[x][y] == State::kEmpty;
  return false;
}

// Helper function to add nodes to the open vector and mark them as closed.
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open, vector<vector<State>> &grid)
{
  open.push_back(vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}

/** 
 * Implementation of A* search algorithm
 */

vector<vector<State>> Search(vector<vector<State>> grid, int start[2], int goal[2])
{
  // Create the vector of open nodes.
  vector<vector<int>> open{};

  // Initialize the starting node.
  int x = start[0];
  int y = start[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);

  // To add the starting node to the open vector.
  AddToOpen(x, y, g, h, open, grid);

  // While open vector is non empty
  while (open.size() > 0)
  {
    // Sort the open node list using CellSort, and get the current node.
    CellSort(&open);
    auto current = open.back(); // Last element contains minimum value of "f"
    open.pop_back();            // Delete last element from open vector reducing the size of the container by one.

    // Get the x and y values from the current node and set grid[x][y] to kPath.
    x = current[0];
    y = current[1];
    grid[x][y] = State::kPath;

    // Check if you've reached the goal. If so, return grid.
    if (x == goal[0] && y == goal[1])
    {
      return grid;
    }
    // If we're not done, expand search to current node's neighbors. This step will be completed in a later quiz.
    // ExpandNeighbors
  }

  cout << "No, Path Found! \n";
  return vector<vector<State>>{};
}

string CellString(State cell)
{
  switch (cell)
  {
  case State::kObstacle:
    return "⛰️   ";
  case State::kPath:
    return "🚗   ";
  default:
    return "0   ";
  }
}

void PrintBoard(const vector<vector<State>> board)
{
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++)
    {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

int main()
{
  // Initizialize
  int init[2] = {0, 0};
  int goal[2] = {4, 5};

  // Read the grid file and parse the content
  auto board = ReadBoardFile("board_1.txt");

  // Search the grid
  auto solution = Search(board, init, goal);

  // Print solution to the terminal
  PrintBoard(solution);
}