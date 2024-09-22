#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n, q, a[100001];
  unordered_map<int,bool> gay;
  cin >> n >> q;

  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(i > 0) a[i] += a[i-1];
    gay[a[i]] = true;
  }

  for(int i = 0; i <= n; i++){
    for(int j = i + 1; j <= n; j++) gay[a[j] - a[i]] = true;
  }
  
  int e;
  for(int i = 0; i < q; i++){
    cin >> e;
    if(gay[e]) cout << "Y";
    else cout << "N";
  }
  
  return 0;
}