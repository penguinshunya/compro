#include "library/main.hpp"

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> to(N);
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    to[u].emplace_back(v);
    to[v].emplace_back(u);
  }
  int K;
  cin >> K;
  vector<pair<int, int>> pd;
  rep(i, K) {
    int p, d;
    cin >> p >> d;
    pd.emplace_back(p - 1, d);
  }
  vector<bool> must_white(N);
  for (auto [p, d] : pd) {
    queue<pair<int, int>> q;
    vector<bool> visited(N);
    q.emplace(p, d);
    visited[p] = true;
    while (q.size()) {
      auto [u, di] = q.front();
      q.pop();
      if (di == 0) break;
      must_white[u] = true;
      for (auto v : to[u]) {
        if (visited[v]) continue;
        q.emplace(v, di - 1);
        visited[v] = true;
      }
    }
  }
  string ans;
  rep(i, N) ans.push_back(must_white[i] ? '0' : '1');
  for (auto [p, d] : pd) {
    queue<pair<int, int>> q;
    vector<bool> visited(N);
    q.emplace(p, d);
    visited[p] = true;
    bool ok = false;
    while (q.size()) {
      auto [u, di] = q.front();
      q.pop();
      if (di == 0) {
        ok |= ans[u] == '1';
        continue;
      }
      for (auto v : to[u]) {
        if (visited[v]) continue;
        q.emplace(v, di - 1);
        visited[v] = true;
      }
    }
    if (!ok) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
  cout << ans << endl;
}
