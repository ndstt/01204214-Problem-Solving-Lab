#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n, m, min = 1000000, res;
  cin >> n >> m;

  int a[n][m];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> a[i][j];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int sum = 0;
      
      for(int k = 0; k < n; k++) if(k != i) sum += abs(a[i][j] - a[k][j]);
      for(int l = 0; l < m; l++) if(l != j) sum += abs(a[i][j] - a[i][l]);
      
      if(sum < min) {
        min = sum;
        res = a[i][j];
      }
    }
  }

  cout << res;
  
  return 0;
}