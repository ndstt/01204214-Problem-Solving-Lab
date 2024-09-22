#include <iostream>
#include <string>
using namespace std;

string y;

int main() {
  string x;
  int xi = 0, res = 0;
  cin >> x;
  cin >> y;

  for(int i = 0; i < y.size(); i++){
    if(x[xi] == y[i]) xi++;
    if(xi == x.size()) {
      res++;
      xi = 0;
    }
  }

  cout << res;
  return 0;
}