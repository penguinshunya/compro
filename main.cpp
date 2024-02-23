#include "library/main.hpp"
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

void solve() {
  vi32 v;
  rep(i, 100) v.push_back(xorshift() % 1000);
  int sum = 0;
  rep(i, 100) sum += v[i];
  cout << sum << endl;
}
