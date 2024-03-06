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

struct Cube {
  int a, b, c;
  Cube(int a, int b, int c) : a(a), b(b), c(c) {}
  int count(Cube x, Cube y) {
    int _a = max(0, (min({a, x.a, y.a}) + 7) - max({a, x.a, y.a}));
    int _b = max(0, (min({b, x.b, y.b}) + 7) - max({b, x.b, y.b}));
    int _c = max(0, (min({c, x.c, y.c}) + 7) - max({c, x.c, y.c}));
    return _a * _b * _c;
  }
  int count(Cube x) { return count(x, x); }
  void print() { cout << a << " " << b << " " << c << endl; }
};

void solve() {
  int V1, V2, V3;
  cin >> V1 >> V2 >> V3;
  vector<Cube> lst;
  repic(i, -7, 7) repic(j, -7, 7) repic(k, -7, 7) {
    lst.push_back(Cube(i, j, k));
  }
  for (auto c2 : lst) {
    for (auto c3 : lst) {
      Cube c1(0, 0, 0);
      int v3 = c1.count(c2, c3);
      int v2 = c1.count(c2) + c2.count(c3) + c3.count(c1) - v3 * 3;
      int v1 = 7 * 7 * 7 * 3 - v2 * 2 - v3 * 3;
      if (v1 == V1 && v2 == V2 && v3 == V3) {
        cout << "Yes" << endl;
        c1.print(), c2.print(), c3.print();
        return;
      }
    }
  }
  cout << "No" << endl;
}
