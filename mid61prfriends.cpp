#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
  if (n <= 1) return false;

  for (int i = 2; i * i <= n; i++){
    if (n % i == 0) return false;
  }

  return true;
}

int main(){
  int l, r, res = 0;
  cin >> l >> r;

  vector<int> primes;
  for (int i = l; i <= r; i++){
    if (isPrime(i)) primes.push_back(i);
  }

  for (int i = 0; i < primes.size() - 1; i++){
    if(primes[i + 1] - primes[i] == 2) res++;
  }

  cout << res;
  return 0;
}