#include <iostream>
#include <list>
using namespace std;

int main() {
  list<int> x;
  int n, k;
  cin >> n >> k;
  
  int a;
  for (int i = 0; i < n; i++){
    cin >> a;
    x.push_back(a);
  }

  for(int i = 0; i < k; i++){
    int maxres = -1;
    cin >> a;
    for(auto i = x.begin(); i != x.end(); i++){
      int res = 0, sum = 0;
      auto j = i;
      while(j != x.end()){
        //cout << "sum = " << sum << ", *j = " << *j << "\n";
        if(sum < a){
          sum += *j;
          //cout << "result = " << res << ", sum = " << sum << "\n\n";
          res++;
        }
        else break;

        j++;
      }
      if(maxres < res) maxres = res;
    }
    cout << maxres - 1 << "\n";
  }
  return 0;
}


/*
4 1
17
10
20
30
50
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  //input
  int n,k,in,sum=0;
  cin >> n >> k;
  vector<int> v;

  for(int i=0;i<n;i++){
    cin >> in;
    sum+=in;
    v.push_back(sum);
  }

  for(int i=0;i<k;i++){
    cin >> in;
    auto upper = upper_bound(v.begin(),v.end(),in);
    cout << upper-v.begin() << '\n';
  }

  return 0;
}*/