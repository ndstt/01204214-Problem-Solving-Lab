#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  vector<int> h;
  unordered_map<int, int> greater;
  int n;
  cin >> n;
  vector<vector<long long>> dp(n, vector<long long>(n, 0));

  int a;
  for(int i = 0 ; i < n ; i++){
    cin >> a;
    h.push_back(a);
  }

  long long res = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = i + 1 ; j < n ; j++){
      if(h[i] > h[j]){
        //dp[i][0]++;
        for(int k = j + 1 ; k < n ; k++) if(h[j] < h[k]) res++;
      }
    }
  }

  /*for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      cout << dp[i][j] << "  ";
    }
    cout << "\n";
  }*/
  /*
  for(int i = 0 ; i < n ; i++){
    for(int j = 1 ; j < n ; j++){
      res += dp[i][j];
    }
  }*/
  

  cout << res;
  
  return 0;
}