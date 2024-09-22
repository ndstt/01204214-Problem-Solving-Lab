#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAX_N = 50000; 

int n, m, s, t;

vector<pair<int,int>> adj[MAX_N]; //first is node, second is color

void init(){
  cin >> n >> m >> s >> t;
  s--; t--;
  
  int u, v, c;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> c;
    u--; v--;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
}

int redbfs(){
  vector<int> layer, seen;
  list<int> q;
  
  for(int i = 0; i < n; i++){
    layer.push_back(-1);
    seen.push_back(0);
  }

  q.push_back(s);
  layer[s] = 0;

  while(!q.empty()){
    int u = q.front();
    seen[u] = 1;
    q.pop_front();
    if(u == t) return layer[u];

    for(pair<int,int> v : adj[u]){
      if(!seen[v.first] && v.second != 2){
        seen[v.first] = 1;
        q.push_back(v.first);
        layer[v.first] = layer[u] + 1;
      }
    }
  }

  return -1;
}

int blackbfs(){
  vector<int> layer, seen;
  list<int> q;

  for(int i = 0; i < n; i++){
    layer.push_back(-1);
    seen.push_back(0);
  }

  q.push_back(s);
  layer[s] = 0;

  while(!q.empty()){
    int u = q.front();
    seen[u] = 1;
    q.pop_front();
    if(u == t) return layer[u];

    for(pair<int,int> v : adj[u]){
      if(!seen[v.first] && v.second != 1){
        seen[v.first] = 1;
        q.push_back(v.first);
        layer[v.first] = layer[u] + 1;
      }
    }
  }

  return -1;
}  

int main() {
  init();
  int res = -1;
  int red = redbfs();
  int black = blackbfs();

  if(red == -1 && black != -1) res = black;
  else if(red != -1 && black == -1) res = red;
  else if(red != -1 && black != -1) res = (red < black) ? red : black;

  cout << res;
  return 0;
}