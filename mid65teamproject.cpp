#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAX_N = 100000;

int n, m, k;

vector<int> seen, color, deg;
vector<int> adj[MAX_N];

void init(){
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
    seen.push_back(0);
    color.push_back(-1);
    deg.push_back(0);
  }

  int u, v;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);

    deg[u]++; deg[v]++;
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
      if(deg[i] >= k) continue;
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

int main() {
  init();
  bool Bipartite = true;

  for(int u = 0; u < n; u++) if(!seen[u] && deg[u] < k) Bipartite &= isBipartite(u);

  cout << (Bipartite ? "yes" : "no") << "\n";
  
  return 0;
}