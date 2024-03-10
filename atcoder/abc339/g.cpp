#line 1 "library/main.hpp"
#include <bits/stdc++.h>
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

// template <typename T = i64> struct Vec2 {
//   T x, y;
//   Vec2() : x(0), y(0) {}
//   Vec2(T x, T y) : x(x), y(y) {}
//   Vec2 &operator+=(Vec2 that) {
//     x += that.x, y += that.y;
//     return *this;
//   }
//   Vec2 &operator-=(Vec2 that) {
//     x -= that.x, y -= that.y;
//     return *this;
//   }
//   Vec2 &operator*=(T s) {
//     x *= s, y *= s;
//     return *this;
//   }
//   Vec2 &operator/=(T s) {
//     x /= s, y /= s;
//     return *this;
//   }
//   Vec2 operator+(Vec2 that) const { return Vec2(*this) += that; }
//   Vec2 operator-(Vec2 that) const { return Vec2(*this) -= that; }
//   Vec2 operator*(T that) const { return Vec2(*this) *= that; }
//   Vec2 operator/(T that) const { return Vec2(*this) /= that; }
//   T dot(Vec2 that) const { return x * that.x + y * that.y; }
//   T cross(Vec2 that) const { return x * that.y - y * that.x; }
//   T length() const { return hypot(x, y); }
//   Vec2 normal() const { return Vec2(*this) / (*this).length(); }

//   T manhattan(const Vec2 &that) {
//     return abs(this->x - that.x) + abs(this->y - that.y);
//   }

//   Vec2 rotate90() { return Vec2(-this->y, this->x); }

//   friend istream &operator>>(istream &is, Vec2 &v) { return is >> v.x >> v.y;
//   }

//   friend ostream &operator<<(ostream &os, Vec2 &v) {
//     return os << v.x << " " << v.y;
//   }
// };

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>

// using Bint = boost::multiprecision::cpp_int;
// using Real =
//     boost::multiprecision::number<boost::multiprecision::cpp_dec_float<128>>;

void solve();

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(16);
  solve();
  return 0;
}
#line 2 "main.cpp"

struct segtree {
  int n;
  vector<vector<i64>> a;
  vector<vector<i64>> s;
  segtree(int ma) {
    n = 1;
    while (n < ma)
      n <<= 1;
    a.resize(n * 2);
    s.resize(n * 2, {0});
  }
  void set(int i, int x) {
    i += n;
    a[i] = {x};
    s[i].push_back(x);
  }
  void build() {
    for (int i = n - 1; i > 0; i--) {
      int l = i * 2, r = l | 1;
      merge(all(a[l]), all(a[r]), back_inserter(a[i]));
      int m = a[i].size();
      s[i].resize(m + 1, 0);
      reps(j, m) s[i][j] = s[i][j - 1] + a[i][j - 1];
    }
  }
  i64 sum(int i, int x) {
    int j = upper_bound(all(a[i]), x) - a[i].begin();
    return s[i][j];
  }
  i64 query(int l, int r, int x) {
    i64 ret = 0;
    l += n, r += n;
    while (l < r) {
      if (l & 1) ret += sum(l++, x);
      if (r & 1) ret += sum(--r, x);
      l >>= 1, r >>= 1;
    }
    return ret;
  }
};

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  cin >> A;
  segtree seg(N);
  rep(i, N) { seg.set(i, A[i]); }
  seg.build();
  int Q;
  cin >> Q;
  i64 ans = 0;
  rep(qi, Q) {
    i64 al, be, ga;
    cin >> al >> be >> ga;
    int L = al ^ ans;
    int R = be ^ ans;
    int X = ga ^ ans;
    L--;
    ans = seg.query(L, R, X);
    cout << ans << '\n';
  }
}
