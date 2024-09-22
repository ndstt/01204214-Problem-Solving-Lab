#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c, a, b, x, y;
const int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<vector<int>> m;
bool seen[30][30];
int layer[30][30];

void init(){
  cin >> r >> c >> a >> b >> x >> y;
  a--; b--; x--; y--;
  
  int input;
  for(int i = 0; i < r; i++){
    vector<int> t;
    for(int j = 0; j < c; j++){
      cin >> input;
      t.push_back(input);
      seen[i][j] = false;
      layer[i][j] = -1;
    }
    m.push_back(t);
  }
}

bool isInBound(int x, int y){
  return x >= 0 && x < r && y >= 0 && y < c;
}

void bfs(){
  queue<pair<int,int>> q;
  q.push(make_pair(a, b));
  layer[a][b] = 0;
  seen[a][b] = true;

  while(!q.empty()){
    pair<int,int> u = q.front();
    q.pop();

    for(int i = 0; i < 4; i++){
      int vx = u.first + di[i][0],
          vy = u.second + di[i][1];
      if(isInBound(vx, vy) && !seen[vx][vy]){
        q.push({vx, vy});
        seen[vx][vy] = true;
        if(m[u.first][u.second] == m[vx][vy]) layer[vx][vy] = layer[u.first][u.second];
        else layer[vx][vy] = layer[u.first][u.second] + 1;
      }
    }
  }
}

int main() {
  init();
  bfs();
  cout << layer[x][y];

  return 0;
}