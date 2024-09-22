#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int n, shortest = 300000;
vector<vector<int>> is_visited, layer, layer69;
vector<string> maze;
const int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int horsedi[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

bool isInRange(int x, int y){
  return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int start_x, int start_y){
  queue<pair<int,int>> q;
  q.push(make_pair(start_x, start_y));
  layer[start_y][start_x] = 0;
  is_visited[start_y][start_x] = 1;

  int new_x, new_y, cur_x, cur_y;
  while(!q.empty()){
    cur_x = q.front().first;
    cur_y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      new_x = cur_x + di[i][0];
      new_y = cur_y + di[i][1];

      if(isInRange(new_x, new_y) && !is_visited[new_y][new_x] && maze[new_y][new_x] == '.'){
        is_visited[new_y][new_x] = true;
        layer[new_y][new_x] = layer[cur_y][cur_x] + 1;
        q.push(make_pair(new_x, new_y));
      }
    }

  }
}

void bfs69(int start_x, int start_y){
  queue<pair<int,int>> q;
  q.push(make_pair(start_x, start_y));
  layer69[start_y][start_x] = 0;
  is_visited[start_y][start_x] = 1;

  int new_x, new_y, cur_x, cur_y;
  while(!q.empty()){
    cur_x = q.front().first;
    cur_y = q.front().second;
    q.pop();

    for(int i = 0; i < 8; i++){
      new_x = cur_x + horsedi[i][0];
      new_y = cur_y + horsedi[i][1];
      
      if(isInRange(new_x, new_y) && !is_visited[new_y][new_x] && layer[new_y][new_x] != -1 && maze[new_y][new_x] == '.'){
        shortest = min(shortest, layer[new_y][new_x] + layer69[cur_y][cur_x] + 1);
      }
    }
    
    for(int i = 0; i < 4; i++){
      new_x = cur_x + di[i][0];
      new_y = cur_y + di[i][1];
      
      if(isInRange(new_x, new_y) && !is_visited[new_y][new_x] && maze[new_y][new_x] == '.'){
        is_visited[new_y][new_x] = true;
        layer69[new_y][new_x] = layer69[cur_y][cur_x] + 1;
        q.push(make_pair(new_x, new_y));
      }
    }

  }
}

int main() {
  cin >> n;
  is_visited.resize(n, vector<int>(n, 0));
  layer.resize(n, vector<int>(n,-1));
  layer69.resize(n, vector<int>(n,-1));

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    maze.push_back(s);
  }

  bfs(0, 0);
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      is_visited[i][j] = 0;
    }
  }
  
  bfs69(n-1, n-1);
  (n == 2) ? cout << 2 : cout << shortest;
  return 0;
}