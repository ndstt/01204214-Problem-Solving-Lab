#include <iostream>
#include <list>
using namespace std;

int main() {
  list<int> x;
  int n, res = 0;
  cin >> n;
  
  int p, v;
  
  for (int i = 0 ; i < n ; i++){
    cin >> p >> v;
    x.push_front(v);
  }
  
  int vmax = x.front();
  for(auto i = x.begin(); i != x.end(); i++){
    if (*i >= vmax) vmax = *i;
    else res++;
  }
  
  cout << res;
  return 0;
}