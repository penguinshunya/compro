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

vector<int> sieve(int ma) {
  vector<int> res;
  vector<bool> mem(ma + 1, true);
  mem[0] = mem[1] = false;
  for (int i = 2; i <= ma; i++) {
    if (!mem[i]) continue;
    res.push_back(i);
    for (int j = i * 2; j <= ma; j += i) {
      mem[j] = false;
    }
  }
  return res;
}

inline unsigned long long xorshift() {
  static unsigned long long x = 88172645463325252ull;
  x = x ^ (x << 7);
  return x = x ^ (x >> 9);
}

template <typename T> struct Compress {
  vector<T> v;
  Compress() {}
  Compress(vector<T> v) : v(v) { build(); }
  void insert(T x) { v.push_back(x); }
  void build() {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
  }
  int get(T x) { return lower_bound(all(v), x) - v.begin(); }
  int size() { return v.size(); }
};

template <typename T> struct Combination {
  vector<T> facc;
  vector<T> finv;
  Combination(int max) {
    facc.resize(max + 1);
    finv.resize(max + 1);
    facc[0] = 1;
    for (int i = 0; i < max; i++) {
      facc[i + 1] = facc[i] * (i + 1);
    }
    finv[max] = (T)1 / facc[max];
    for (int i = max; i > 0; i--) {
      finv[i - 1] = finv[i] * i;
    }
  }
  T operator()(int a, int b) {
    if (a < 0 || b < 0 || b > a) return 0;
    return facc[a] * finv[a - b] * finv[b];
  }
};

template <typename T = i64> struct Vec2 {
  T x, y;
  Vec2() : x(0), y(0) {}
  Vec2(T x, T y) : x(x), y(y) {}
  Vec2 &operator+=(Vec2 that) {
    x += that.x, y += that.y;
    return *this;
  }
  Vec2 &operator-=(Vec2 that) {
    x -= that.x, y -= that.y;
    return *this;
  }
  Vec2 &operator*=(T s) {
    x *= s, y *= s;
    return *this;
  }
  Vec2 &operator/=(T s) {
    x /= s, y /= s;
    return *this;
  }
  bool operator==(const Vec2<T> &rhs) const {
    return this->x == rhs.x && this->y == rhs.y;
  }
  Vec2 operator+(Vec2 that) const { return Vec2(*this) += that; }
  Vec2 operator-(Vec2 that) const { return Vec2(*this) -= that; }
  Vec2 operator*(T that) const { return Vec2(*this) *= that; }
  Vec2 operator/(T that) const { return Vec2(*this) /= that; }
  T dot(Vec2 that) const { return x * that.x + y * that.y; }
  T cross(Vec2 that) const { return x * that.y - y * that.x; }
  T length() const { return hypot(x, y); }
  Vec2 normal() const { return Vec2(*this) / (*this).length(); }
  T manhattan(const Vec2 &that) {
    return abs(this->x - that.x) + abs(this->y - that.y);
  }
  Vec2 rotate90() { return Vec2(-this->y, this->x); }
  friend istream &operator>>(istream &is, Vec2 &v) { return is >> v.x >> v.y; }
  friend ostream &operator<<(ostream &os, Vec2 &v) {
    return os << v.x << " " << v.y;
  }
};

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

using P = pair<i64, i64>;

i64 dp[7][7][7][7][36];

void solve() {
  i64 H, W, T;
  cin >> H >> W >> T;
  vector<vector<i64>> S(H, vector<i64>(W));
  cin >> S;
  auto sums = vector(H + 1, vector(W + 1, 0ll));
  reps(i, H) reps(j, W) {
    sums[i][j] += S[i - 1][j - 1];
    sums[i][j] += sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
  }
  auto calc = [&](i64 l, i64 r, i64 t, i64 b) {
    return sums[r][b] - sums[l][b] - sums[r][t] + sums[l][t];
  };
  vector<i64> Ls;
  reps(h, H) reps(w, W) rep(l, H) rep(t, W) {
    i64 r = l + h;
    i64 b = t + w;
    if (r > H || b > W) break;
    Ls.push_back(calc(l, r, t, b));
  }
  i64 ans = LINF;
  for (auto L : Ls) {
    repc(i, 6) repc(j, 6) repc(k, 6) repc(l, 6) rep(m, 36) {
      dp[i][j][k][l][m] = LINF;
    }
    reps(h, H) reps(w, W) rep(l, H) rep(t, W) {
      i64 r = l + h;
      i64 b = t + w;
      if (r > H || b > W) break;
      if (calc(l, r, t, b) >= L) {
        dp[l][r][t][b][0] = calc(l, r, t, b);
      }
      reps(x, T) {
        // 行方向
        repic(c, l + 1, r - 1) {
          rep(y, x) {
            chmin(dp[l][r][t][b][x],
                  max(dp[l][c][t][b][y], dp[c][r][t][b][x - y - 1]));
          }
        }
        // 列方向
        repic(c, t + 1, b - 1) {
          rep(y, x) {
            chmin(dp[l][r][t][b][x],
                  max(dp[l][r][t][c][y], dp[l][r][c][b][x - y - 1]));
          }
        }
      }
    }
    chmin(ans, dp[0][H][0][W][T] - L);
  }
  cout << ans << endl;
}
