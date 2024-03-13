#include "library/main.hpp"

void solve() {
  int N;
  cin >> N;
  vector<map<int, int, greater<int>>> ops(2 * N);
  auto operate = [&](int i, int x, int d) {
    ops[i][x] += d;
    if (ops[i][x] == 0) {
      ops[i].erase(x);
    }
  };
  auto add = [&](int l, int r, int x) {
    l += N, r += N;
    while (l != r) {
      if (l & 1) operate(l++, x, 1);
      if (r & 1) operate(--r, x, 1);
      l /= 2, r /= 2;
    }
  };
  auto del = [&](int l, int r, int x) {
    l += N, r += N;
    while (l != r) {
      if (l & 1) operate(l++, x, -1);
      if (r & 1) operate(--r, x, -1);
      l /= 2, r /= 2;
    }
  };
  auto get = [&](int i) {
    i += N;
    int ret = 0;
    while (i) {
      chmax(ret, ops[i].begin()->first);
      i /= 2;
    }
    return ret;
  };
  rep(i, N) {
    int a;
    cin >> a;
    add(i, i + 1, a);
  }
  int Q;
  cin >> Q;
  vector<tuple<int, int, int>> queries(Q);
  rep(qi, Q) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      add(l, r, x);
      queries[qi] = {l, r, x};
    } else if (type == 2) {
      int i;
      cin >> i;
      i--;
      auto [l, r, x] = queries[i];
      del(l, r, x);
    } else {
      int i;
      cin >> i;
      i--;
      cout << get(i) << '\n';
    }
  }
}
