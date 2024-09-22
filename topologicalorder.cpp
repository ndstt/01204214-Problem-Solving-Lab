#include <iostream>
#include <vector>
using namespace std;

#define MAX_N  100000

int n, m;

vector<int> g[MAX_N], topo;
int outdeg[MAX_N];
int seen[MAX_N];
bool hascycle = false;

void dfs(int u){
  seen[u] = 1;
  for(int j = 0 ; j < outdeg[u] ; j++){
    int v = g[u][j];
    if(seen[v] == 1){
      hascycle = true;
      return;
    }
    if(!seen[v]) dfs(v);
  }
  topo.push_back(u);
  seen[u] = 2;
}

int main() {
  cin >> n >> m;
  
  for(int i = 0; i < n; i++){
    outdeg[i] = 0;
    seen[i] = false;
  } 
  
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    outdeg[a]++;
  }

  for(int i =  0; i < n; i++){
    if(!seen[i]) dfs(i);
  }

  if(hascycle) cout << "no";
  else for(int i = topo.size() - 1 ; i >= 0 ; i--) cout << topo[i] + 1 << "\n";
  
  return 0;
}