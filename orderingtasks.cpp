#include <iostream>
#include <vector>
#include <list>
using namespace std;

void dfs(int u,vector<int> &seen, vector<int> *adj, list<int> &topo){
  seen[u] = 1;
  for(int v : adj[u]){
    if(!seen[v]) dfs(v,seen,adj,topo);
  }
  topo.push_front(u);
  seen[u] = 2;
}

int main() {
  int a, b, n, m;
  
  while(true){
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    
    vector<int> adj[n], seen(n,0);
    list<int> topo;

    for(int i = 0; i < m; i++){
      cin >> a >> b;
      a--; b--;
      adj[a].push_back(b);
    }

    for(int i = 0; i < n; i++){
      if(!seen[i]) dfs(i,seen,adj,topo);
    }

    for(int i :topo) cout << i + 1 << " ";
    cout << "\n";
    
  }
  return 0;
}