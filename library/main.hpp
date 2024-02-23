#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ll << (b))

using namespace std;

using i32 = int;
using i64 = long long;
using f64 = double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf64 = vector<f64>;
using vstr = vector<string>;

template <typename T, typename S>
inline bool chmax(T &a, const S &b) {
  return ((a > b) ? (a = b, true) : (false));
}

template <typename T, typename S>
inline bool chmin(T &a, const S &b) {
  return ((a < b) ? (a = b, true) : (false));
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  each(x, v) is >> x;
  return is;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
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
