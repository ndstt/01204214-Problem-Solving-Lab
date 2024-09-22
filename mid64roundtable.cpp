#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int f[n], foodrotate[n], round[n];
  
  for(int i = 0; i < n; i++){
    cin >> f[i];
    f[i]--;
    foodrotate[i] = 0;
    round[i] = 0;
  }
  
  for(int i = 0; i < n; i++){
    foodrotate[f[i]] =  f[i] - i;
    if(foodrotate[f[i]] < 0) foodrotate[f[i]] += n;
  }
  
  for(int i : foodrotate) round[i]++;

  int max = -1;
  for(int i : round){
    max = (i > max) ? i : max;
    if(max == n) break;
  }

  cout << max;
  
  return 0;
}