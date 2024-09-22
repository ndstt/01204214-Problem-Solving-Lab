#include <iostream>
#include <string>
#include <vector>
using namespace std;

string x, y;
int n, m;
vector<vector<int>> dp;

int lcs(int i, int j) {
    if (i == 0 || j == 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (x[i - 1] == y[j - 1]) dp[i][j] = 1 + lcs(i - 1, j - 1);
    else dp[i][j] = 0;

    return max(dp[i][j], max(lcs(i, j - 1), lcs(i - 1, j)));
}

int main() {
    cin >> x >> y;
    n = x.length();
    m = y.length();

    dp.assign(n + 1, vector<int>(m + 1, -1));

    cout << lcs(n, m) + 1;

    return 0;
}
