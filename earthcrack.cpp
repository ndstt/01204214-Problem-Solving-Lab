#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  for(int i = 0 ; i < t ; i++){
    int m, n, minnum = 1000000;
    cin >> m >> n;
    int firstlineminindex = n - 1;
    vector<vector<int>> a;
    for(int j = 0 ; j < m ; j++){
      vector<int> b;
      int q;
      for(int k = 0 ; k < n ; k++){
        cin >> q;
        b.push_back(q);
        if(j == 0 && q < minnum && k != 0 && k != n - 1){
          firstlineminindex = k;
          minnum = q;
          cout << "\nminnum = " << minnum << " ";
          cout << "\nminindex = " << firstlineminindex << " ";
        }
      }
      a.push_back(b);
    }

    int sum = minnum,
        minindex = firstlineminindex;
    for(int j = 1 ; j < m ; j++){
      int min = a[j][minindex];
      if(minindex > 0 && minindex < m) {
        int tempmin = min;
        if(a[j][minindex - 1] < tempmin){
          int left = minindex - 1;
          min = a[j][left];
          minindex = left;
        }
        if(a[j][minindex + 1] < min){
          int right = minindex + 1;
          min = a[j][minindex + 1];
          minindex = right;
        }
      }
      else if(minindex == 0){
        if(a[j][minindex + 1] < min){
          min = a[j][minindex + 1];
          minindex++;
        }
      }
      else if(minindex == n - 1){
        if(a[j][minindex - 1] < min){
          min = a[j][minindex - 1];
          minindex--;
        }
      }
      sum += min;
      cout << "\nmin = " << min << " minindex = " << minindex << " sum = " << sum << " ";
    }
    cout << "\n" << sum << "\n";
  }
  
  return 0;
}

/*
2
8 5
1 6 7 2 3
7 9 5 2 1
1 1 8 8 6
6 5 6 3 9
9 1 4 8 6
4 2 9 7 7
2 3 2 5 8
5 8 2 4 4
*/