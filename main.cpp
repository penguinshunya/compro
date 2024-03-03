#include "library/main.hpp"

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> to(N);
  rep(i, N - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    to[u].emplace_back(v);
    to[v].emplace_back(u);
  }
  i64 ans = 0;
  auto dfs = [&](auto dfs, int u, int p) -> int {
    vector<int> sums;
    for (auto v : to[u]) {
      if (v == p) continue;
      sums.push_back(dfs(dfs, v, u));
    }
    int su = accumulate(all(sums), 0);

    sums.push_back(N - su - 1);
    vector<i64> dp_(4);
    dp_[0] = 1;
    for (auto sum : sums) {
      rreps(i, 3) dp_[i] += dp_[i - 1] * sum;
    }
    ans += dp_[3];
    sums.pop_back();

    return su + 1;
  };
  dfs(dfs, 0, -1);
  cout << ans << endl;
}
