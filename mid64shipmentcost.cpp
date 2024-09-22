#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAX_N = 100000; 

int n, m, s, t;

vector<int> adj[MAX_N];
vector<int> layer, seen;
list<int> q;

void bfs(){
  int a;
  for(int i = 0; i < s; i++){
    cin >> a;
    a--;
    q.push_back(a);
    layer[a] = 0;
    seen[a] = 1;
  }

  while(!q.empty()){
    int u = q.front();
    q.pop_front();
    seen[u] = 1;
    for(int v : adj[u]){
      if(!seen[v]){
        seen[v] = 1;
        layer[v] = layer[u] + 1;
        q.push_back(v);
      }
    }
  }
}

void init(){
  cin >> n >> m >> s >> t;

  for(int i = 0; i < n; i++){
    layer.push_back(-1);
    seen.push_back(0);
  }

  int u, v;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bfs();
  
  for(int i = 0; i < t; i++){
    cin >> u;
    u--;
    cout << layer[u] << "\n";
  }
}

int main() {
  init();
  
  return 0;
}