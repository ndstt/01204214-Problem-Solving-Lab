#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> team;
vector<bool> seen;
vector<int> adj[100000];

bool isBipartite(int s){
  list<int> Q;
  Q.push_back(s);
  seen[s] = true;
  team[s] = 0;

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop_front();
    for(int v : adj[u]) {
      if(!seen[v]) {
        Q.push_back(v);
        seen[v] = true;
        team[v] = !team[u];
      }
      else if(team[u] == team[v]) return false;
    }
  }
  return true;
}

void reset(int s){
  //cout << "Reseting reachable nodes of u\n";
  list<int> Q;
  Q.push_back(s);
  seen[s] = false;
  team[s] = -1;
  //cout << "seen[" << s + 1 << "] = " << seen[s] << " team[" << s + 1 << "] = " << team[s] << "\n";

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop_front();
    for(int v : adj[u]) {
      if(seen[v]) {
        Q.push_back(v);
        seen[v] = false;
        team[v] = -1;
        //cout << "seen[" << v + 1 << "] = " << seen[v] << " team[" << v + 1 << "] = " << team[v] << "\n";
      }
    }
  }
}

int main(){
  int n, m;
  cin >> n >> m;


  for(int i = 0; i < n; i++){
    team.push_back(-1);
    seen.push_back(false);
  }

  int u, v;
  bool bipartite = true;

  for(int i = 0; i < m; i++){
    cin >> u >> v;
    u--; v--;

    adj[u].push_back(v);
    adj[v].push_back(u);

    if(!seen[u] && !seen[v]){
      seen[u] = true; seen[v] = true;
      team[u] = 0; team[v] = 1;
    }
    else if(!seen[u]){
      seen[u] = true;
      team[u] = !team[v];
    }
    else if(!seen[v]){
      seen[v] = true;
      team[v] = !team[u];
    }
    else {
      if(team[u] == team[v]){
        reset(u);
        //cout << "\n";
        bipartite &= isBipartite(u);
        //cout << "Biparite: " << bipartite << "\n\n";
      }
    }

    if(!bipartite) {
      cout << i;
      break;
    }
  }

  return 0;
}