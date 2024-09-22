#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_N = 100010;

int n,m;
vector<int> adj[MAX_N];
vector<int> weights[MAX_N];
vector<int> isgood[MAX_N];

vector<pair<int,int>> edges;
vector<int> edge_weights;
vector<int> edge_status;

set<pair<int,int>> Q;

vector<pair<int,int>> sedges;

void read_input(){
  cin >> n >> m;
  
  for(int i = 0; i < m; i++) {
    int a, b, w, d;
    cin >> a >> b >> w >> d;  a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    
    weights[a].push_back(w);
    weights[b].push_back(w);
    
    isgood[a].push_back(d);
    isgood[b].push_back(d);

    edges.push_back(make_pair(a,b));
    edge_weights.push_back(w);
    edge_status.push_back(d);

    sedges.push_back(make_pair(w,i));
  }
}

int set_parent[MAX_N];
int set_rank[MAX_N];

void init_set(){
  for(int i=0; i<n; i++) {
    set_parent[i] = i;
    set_rank[i] = 1;
  }
}

int set_find(int u){
  if(set_parent[u] == u) return u;
  else return set_find(set_parent[u]);
}

void set_union(int pu, int pv){
  pu = set_find(pu);
  pv = set_find(pv);
  
  if(pu == pv) return;
  
  if(set_rank[pv] > set_rank[pu]) set_parent[pu] = pv;
  else if(set_rank[pu] > set_rank[pv]) set_parent[pv] = pu;
  else{
    set_parent[pv] = pu;
    set_rank[pu]++;
  }
}

int main(){
  int total = 0;
  read_input();
  init_set();
  sort(sedges.begin(), sedges.end());
  for(int i=0; i<m; i++) {
    int e = sedges[i].second;
    int u = edges[e].first;
    int v = edges[e].second;
    int d = edge_status[e];

    int pu = set_find(u);
    int pv = set_find(v);
    if(pu != pv && d) set_union(pu,pv);
  }

  for(int i=0; i<m; i++) {
    int e = sedges[i].second;
    int u = edges[e].first;
    int v = edges[e].second;
    int w = edge_weights[e];
    int d = edge_status[e];

    int pu = set_find(u);
    int pv = set_find(v);
    if(pu != pv && !d) {
      total += w;
      set_union(pu,pv);
    }
  }
  
  cout << total << endl;
  return 0;
}