#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n,in,max_index,max_count;
  cin >> n;
  unordered_map<int, int> humlek;

  for (int i = 0; i < n; i++) {
    cin >> in;
    if(humlek.find(in) == humlek.end()) {
      humlek[in] = 1;
      if (i == 0){ 
        max_index = in;
        max_count = humlek[in];
      }
    }
    else humlek[in]++;
    
    if (max_count <= humlek[in]){
      max_index = in;
      max_count = humlek[in];
    }

    cout << max_index << "\n";
  }
  
  return 0;
}
