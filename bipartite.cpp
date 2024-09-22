#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 100010;

int m,n;
vector<int> adj[MAX_N];
vector<int> color;
int seen[MAX_N];

void read_input(){
  cin >> n >> m;

  for(int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void init(){
  for(int u = 0; u < n; u++){
    seen[u] = false;
    color[u] = -1;
  }
}

bool isBipartite(int s){
  list<int> Q;
  Q.push_back(s);
  seen[s] = true;
  color[s] = 0;

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop_front();
    for(int i : adj[u]) {
      if(!seen[i]) {
        Q.push_back(i);
        seen[i] = true;
        color[i] = 1 - color[u];
      }
      else if(color[i] == color[u]) return false;
    }
  }
  return true;
}

int main(){
  int k;
  cin >> k;
  init();

  for(int i = 0; i < k; i++){
    read_input();
    color.resize(n);
    bool Bipartite = true;

    for(int u = 0; u < n; u++) if(!seen[u]) Bipartite &= isBipartite(u);

    cout << (Bipartite ? "yes" : "no") << "\n";

    for(int node = 1; node <= n; node++){
      adj[node].clear();
      seen[node] = false;
    }
  }
  return 0;
}