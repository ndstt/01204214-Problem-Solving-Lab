#include <iostream>
using namespace std;

int n, m;
char **maze;
bool **seen;

void displayMaze() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maze[i][j];
        }
        cout << "\n";
    }
}

void init() {
    cin >> n >> m;

    maze = new char*[n];
    for (int i = 0; i < n; ++i) {
        maze[i] = new char[m];
    }

    seen = new bool*[n];
    for (int i = 0; i < n; ++i) {
        seen[i] = new bool[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            seen[i][j] = (maze[i][j] == '.') ? false : true;
        }
    }
}

bool dfs(int x, int y) {
    if (x < 0 || x + 1 >= m || y < 0 || y + 1 >= n) return false;
    if (seen[y][x] && seen[y][x + 1] && seen[y + 1][x] && seen[y + 1][x + 1]) return false;
    if (maze[y][x] != '.' || maze[y + 1][x] != '.' || maze[y][x + 1] != '.' || maze[y + 1][x + 1] != '.') return false;
    if (y + 1 == n - 1 && maze[y][x] == '.' && maze[y + 1][x] == '.' && maze[y][x + 1] == '.' && maze[y + 1][x + 1] == '.') return true;
  
    seen[y][x] = true;
    seen[y][x + 1] = true;
    seen[y + 1][x] = true;
    seen[y + 1][x + 1] = true;

    if (dfs(x + 1, y)) return true;
    if (dfs(x, y + 1)) return true;
    if (dfs(x - 1, y)) return true;
    if (dfs(x, y - 1)) return true;

    return false;
}

int main() {
    init();

    bool canReachEnd = false;
    for(int i = 0; i < m; i++){
      canReachEnd |= dfs(i, 0);
      if(canReachEnd){
        cout << "yes";
        break;
      }
    }
    if(!canReachEnd) cout << "no";
    return 0;
}