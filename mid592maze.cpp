#include <iostream>
#include <string>
using namespace std;

const int di[4][2]= {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
bool seen[20][20];
string maze[20];
int n, q;

void init(){
  for(int i = 0;i < n;i++){
    cin >> maze[i];
    for(int j = 0;j < n;j++) seen[i][j] = false;
  } 
}

bool isInBoundary(int x, int y){
  return x >= 0 && x < n && y >= 0 && y < n;
}

bool dfs(int sy, int sx, int dy, int dx, int key){
  //cout << "Current Postion: " << sy + 1 << " " << sx + 1<< "\nKey left: " << key << "\n";
  if(maze[sy][sx] == '#' || (maze[sy][sx] == 'O' && key == 1)) return false;
  
  if(sy == dy && sx == dx) return true;
  seen[sy][sx] = true;

  for(int i = 0;i < 4;i++){
    int ny = sy + di[i][1], nx = sx + di[i][0];
    if(isInBoundary(nx, ny) && !seen[ny][nx]){
      if(maze[ny][nx] == '.'){
        //cout << "Now enter: " << ny + 1 << " " << nx + 1 << "\n";
        if(dfs(ny, nx, dy, dx, key)) return true;
      }  
      else if(maze[ny][nx] == 'O' && key >= 1){
        //cout << "Now enter: " << ny + 1 << " " << nx + 1 << "\n";
        if(dfs(ny, nx, dy, dx, key-1)) return true;
      }
    }
  }
  //cout << "\nPath for " << sy + 1 << " " << sx + 1 << " is end\n";;
  return false;
}

void reset(){
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++) seen[i][j] = false;
  }
}

int main(){
  int y1 = 10, x1 = 1, y2 = 6, x2 = 10;
  cin >> n >> q;
  init();

  for(int i = 0;i < q;i++){
    cin >> y1 >> x1 >> y2 >> x2;
    y1--; x1--; y2--; x2--;
    cout << "\n";
    dfs(y1, x1, y2, x2, 1) ? cout << "yes\n": cout << "no\n";
    reset();
  }
  return 0;
}

/*
10 10
......#...
......O...
......#...
##O#####O#
...#......
...#......
####O#####
......#...
......O...
......#...
1 1 1 10
1 1 5 10
6 1 1 10
10 1 6 10
8 1 10 9
10 1 1 10
10 3 6 8
10 5 2 5
6 10 1 10
6 10 1 1
6 10 1 1
*/

/*
yes
no
no
yes
yes
no
yes
no
yes
no
*/