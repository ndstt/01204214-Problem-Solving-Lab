#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 100010;

int n,w;
vector<int> adj[MAX_N];
vector<int> weights[MAX_N];

vector<pair<int,int>> edges;
vector<int> edge_weights;
vector<int> edge_status;

set<pair<int,int>> Q;

vector<pair<int,int>> sedges;

int seen[MAX_N];
int set_number[MAX_N];

void init_set(){
  for(int i=0; i<n; i++){
    set_number[i] = i;
    seen[i] = 0;
  }
}

int set_find(int u){
  return set_number[u];
}

void set_union(int pu, int pv){
  for(int i=0; i<n; i++)
    if(set_number[i] == pu) set_number[i] = pv;
}

int main(){
  cin >> n >> w;
  for(int i = 0; i < w; i++) {
    int a, b, w;
    cin >> a >> b >> w;  a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);

    weights[a].push_back(w);
    weights[b].push_back(w);

    edges.push_back(make_pair(a,b));
    edge_weights.push_back(w);

    sedges.push_back(make_pair(w,i));

    int total = 0;
    init_set();
    sort(sedges.begin(), sedges.end());
    for(int j = 0; j < n; j++) {
      int e = sedges[j].second;
      int u = edges[e].first;
      int v = edges[e].second;
      int we = edge_weights[e];

      int pu = set_find(u);
      int pv = set_find(v);
      if(pu != pv) {
        total += we;
        set_union(pu,pv);
      }
    }

    bool mst = true;
    for(int j = 1; j < n; j++){
      if(set_find(j) != set_find(0)){
        mst = false;
        break;
      }
    }

    if(mst) cout << total << "\n";
    else cout << "-1\n";
  }

  return 0;
}