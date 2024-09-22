#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int cured[n];

  for(int i = 0; i < n; i++) cured[i] = 0;

  for(int i = 0 ; i < n ; i++){
    int l;
    cin >> l;
    for(int j = 0 ; j < l ; j++){
      int a,b;
      cin >> a >> b;
      if(i + b < n) cured[i + b] += a;
    }
  }

  cout << "\n";
  for (int i = 0; i < n; i++) cout << cured[i] << "\n";
  
  return 0;
}