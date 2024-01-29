#include <iostream>
using namespace std;

const int MAX_N = 100010;

int set_parent[MAX_N];
int set_rank[MAX_N];

int set_find(int u) {
  if(set_parent[u] == u) return u;
  else return set_find(set_parent[u]);
}

void set_union(int pu, int pv) {
  pu = set_find(pu);
  pv = set_find(pv);
  if(pu == pv) return ;
  
  if(set_rank[pv] > set_rank[pu]) set_parent[pu] = pv;
  else if(set_rank[pu] > set_rank[pv]) set_parent[pv] = pu;
  else {
    set_parent[pv] = pu;
    set_rank[pu]++;
  }
}

int main() {
  int n, q, u, v;
  char a;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    set_parent[i] = i;
    set_rank[i] = 1;
  }
  
  for(int i = 0; i < q; i++){
    cin >> a;
    if (a == 'q'){
      cin >> u >> v;
      if(set_find(u) == set_find(v)) cout << "yes\n";
      else cout << "no\n";
    }
    else if (a == 'c'){
      cin >> u >> v;
      set_union(u,v);
    }
  }
  
  return 0;
}
