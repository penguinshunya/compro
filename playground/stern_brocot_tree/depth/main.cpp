#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using Bint = boost::multiprecision::cpp_int;

using T = tuple<Bint, Bint, Bint, Bint>;

Bint gcd(Bint a, Bint b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  Bint gx, gy;
  cin >> gx >> gy;
  auto g = gcd(gx, gy);
  gx /= g, gy /= g;
  auto dfs = [&](auto dfs, T t) -> int {
    auto [a, b, c, d] = t;
    auto x = a + c;
    auto y = b + d;
    if (x * gy == y * gx) {
      return 0;
    }
    if (y * gx < x * gy) {
      auto p = gy * x - gx * y;
      auto q = gx * b - gy * a;
      auto r = (p + q - 1) / q;
      return dfs(dfs, T(a * r, b * r, x, y)) + 1;
    } else {
      auto p = gx * y - gy * x;
      auto q = gy * c - gx * d;
      auto r = (p + q - 1) / q;
      return dfs(dfs, T(x, y, c * r, d * r)) + 1;
    }
  };
  int ans = dfs(dfs, T(0, 1, 1, 0));
  cout << ans << endl;
  return 0;
}
