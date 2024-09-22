#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<int> seen, color;

bool isBipartite(int s, vector<int> *adj, pair<int,int> p){
  list<int> Q;
  Q.push_back(s);
  seen[s] = true;
  color[s] = 0;

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop_front();
    for(int i : adj[u]) {
      //cout << "u: " << u + 1 << ", i: " << i + 1 << "\n";
      if((u == p.first && i == p.second) || (i == p.first && u == p.second)) continue;
      if(!seen[i]) {
        Q.push_back(i);
        seen[i] = true;
        color[i] = !color[u];
      }
      else if(color[i] == color[u]) return false;
    }
  }
  return true;
}

int main(){
  int n, m;
  cin >> n >> m;

  vector<int> adj[n];
  list<pair<int,int>> p;

  seen.resize(n,0);
  color.resize(n,-1);

  int u, v;
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    u--; v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    p.push_back({u, v});
  }

  //do
  for(pair<int,int> pa : p){
    //cout << "If have no " << pa.first + 1 << " " << pa.second + 1 << " pair\n";
    bool bipartite = true;

    for(int i = 0; i < n; i++){
      if(!seen[i]) bipartite &= isBipartite(i, adj, pa);    
    }
    if(bipartite){
      cout << pa.first + 1 << " " << pa.second + 1;
      break;
    }
    //reset
      for(int i = 0; i < n; i++){
        color[i] = -1;
        seen[i] = 0;
      }
  }

  return 0;
}