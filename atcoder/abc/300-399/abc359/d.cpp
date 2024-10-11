#line 1 "library/main.hpp"
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

using i64 = long long;
using f80 = long double;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define rrepi(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define rrepic(i, a, b) for (int i = int(b); i >= int(a); i--)
#define all(a) (a).begin(), (a).end()

const int INF = 1001001001;
const i64 LINF = 1001001001001001001ll;
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

template <typename T> T floor(T x, T y) {
  assert(y != 0);
  if (y < 0) x = -x, y = -y;
  return (x >= 0 ? x / y : (x - y + 1) / y);
}

template <typename T> T ceil(T x, T y) {
  assert(y != 0);
  if (y < 0) x = -x, y = -y;
  return (x >= 0 ? (x + y - 1) / y : x / y);
}

i64 gcd(i64 a, i64 b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }

pair<i64, i64> extgcd(i64 a, i64 b) {
  if (b == 0) return make_pair(1, 0);
  auto [y, x] = extgcd(b, a % b);
  y -= a / b * x;
  return make_pair(x, y);
}

template <typename T> inline T power(T x, i64 n, T e = 1) {
  T r = e;
  while (n > 0) {
    if (n & 1) r *= x;
    n >>= 1, x *= x;
  }
  return r;
}

template <typename T, typename S> inline bool chmax(T &a, const S &b) {
  return ((a < b) ? (a = b, true) : false);
}

template <typename T, typename S> inline bool chmin(T &a, const S &b) {
  return ((a > b) ? (a = b, true) : false);
}

template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v)
    is >> x;
  return is;
}

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  rep(i, v.size()) {
    if (i) os << ' ';
    os << v[i];
  }
  return os;
}

template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &p) {
  os << p.first << ' ' << p.second;
  return os;
}

inline unsigned long long xorshift() {
  static unsigned long long x = 88172645463325252ull;
  x = x ^ (x << 7);
  return x = x ^ (x >> 9);
}

void solve();

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(16);
  solve();
  return 0;
}
#line 2 "main.cpp"
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

mint dp[1010][1050];

void solve() {
  int n, k;
  cin >> n >> k;
  string S;
  cin >> S;
  auto judge = [&](int s) {
    for (int l = 0; l < k / 2; l++) {
      int r = k - l - 1;
      if (((s >> l) & 1) != ((s >> r) & 1)) {
        return true;
      }
    }
    return false;
  };
  for (int s = 0; s < (1 << k); s++) {
    bool ok = true;
    for (int i = 0; i < k; i++) {
      if (S[i] == '?') continue;
      int c = S[i] - 'A';
      if ((s >> (k - i - 1) & 1) != c) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    if (judge(s)) {
      dp[0][s] = 1;
    }
  }
  for (int i = 0; i + k + 1 <= n; i++) {
    int ni = i + 1;
    vector<int> next;
    if (S[ni + k - 1] == 'A') next.push_back(0);
    if (S[ni + k - 1] == 'B') next.push_back(1);
    if (S[ni + k - 1] == '?') {
      next.push_back(0);
      next.push_back(1);
    }
    for (int s = 0; s < (1 << k); s++) {
      if (dp[i][s] == 0) continue;
      for (auto j : next) {
        int ns = (s << 1) & ((1 << k) - 1) | j;
        if (judge(ns)) {
          dp[ni][ns] += dp[i][s];
        }
      }
    }
  }
  mint ans = 0;
  for (int s = 0; s < (1 << k); s++) {
    ans += dp[n - k][s];
  }
  cout << ans.val() << endl;
}
