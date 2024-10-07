#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;

ll n;
vl A;
vvl dp;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  A = vl(n);
  for (auto&& a : A) {
    cin >> a;
  }

  dp = vvl(n, vl(21, 0));
  dp[0][A[0]] = 1;
  for (auto i = 1; i < n - 1; ++i) {
    for (auto j = 0; j <= 20; ++j) {
      if (j - A[i] >= 0) {
        dp[i][j - A[i]] += dp[i - 1][j];
      }
      if (j + A[i] <= 20) {
        dp[i][j + A[i]] += dp[i - 1][j];
      }
    }
  }

  cout << dp[n - 2][A[n - 1]];

  return 0;
}