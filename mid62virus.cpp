#include <iostream>
#include <list>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  list<int> a;

  for(int i = 0; i < n; i++){
    int q;
    cin >> q;
    a.push_back(q);
  }

  list<int>::iterator idx = a.begin();
  
  for(int i = 0; i < m; i++){
    int t;
    cin >> t;
    if(t == 1) idx = a.begin();
    else if(t == 2){
      idx++;
      if(idx == a.end()) idx = a.begin();
    }
    else if(t == 3){
      int x;
      cin >> x;
      if(idx != a.begin()) a.insert(idx, x);
      else a.push_front(x);
    }
    else if(t == 4){
      int x;
      cin >> x;
      if(idx != a.end()) {
        auto it = idx;
        a.insert(++it, x);
      }
      else a.push_back(x);
    }
  }

  for(int g : a) cout << g << "\n";
  return 0;
}

/*
3 11
1 2 3
3 100
2
4 500
1
2
2
2
2
3 50
2
4 99
4 99
*/