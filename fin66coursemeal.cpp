#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> x, y, z, opt;
  int a, b, c;
  
  for(int i = 0; i < n; i++){
    cin >> a >> b >> c;
    x.push_back(a);
    y.push_back(b);
    z.push_back(c);
    opt.push_back(0);
  }
  
  for(int i = n - 1; i >= 0; i--){
    for(int j = i - 1; j >= 0; j--){
      opt[i] = max(opt[i], opt[j] + x[i] * y[j]);
    }
  }
  
  return 0;
}