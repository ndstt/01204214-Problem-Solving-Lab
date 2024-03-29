#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 1000010,
          INFINITY = 1000000000;

vector<int> adj[MAX_N], lenght[MAX_N];

int dist[MAX_N], n, m;
bool scanned[MAX_N];
set<pair<int,int>> q;

void input(){
  cin >> n >> m;
  int u, v, w;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    lenght[u].push_back(w);
    lenght[v].push_back(w);
  }
}

void dijkstra(int s){
  for(int u = 0; u < n; u++){
    dist[u] = INFINITY;
    scanned[u] = false;
  }
  
  dist[s] = 0;
  //find min d[u]
  q.insert(make_pair(0,s));
  while(!q.empty()){
    auto pu = *q.begin();
    q.erase(q.begin());
    int u = pu.second;
    if(scanned[u]) continue;

    scanned[u] = true;

    int deg = adj[u].size();
    for(int i = 0; i < deg; i++){
      int v = adj[u][i];
      int len = lenght[u][i];

      if(dist[u] + len < dist[v]){
        dist[v] = dist[u] + len;
        q.insert(make_pair(dist[v],v));
      }
    }    
  } 
}

int main() {
  input();
  dijkstra(0);
  cout << dist[n-1];
  
  return 0;
}
