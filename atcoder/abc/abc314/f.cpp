#include "library/main.hpp"

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

void solve() {
  int N;
  cin >> N;
  dsu dsu(N);
  vector<int> parent(N);
  rep(i, N) parent[i] = i;
  vector<pair<int, int>> to(N);
  rep(i, N - 1) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    int pa = to.size();
    int lp = parent[dsu.leader(p)];
    int lq = parent[dsu.leader(q)];
    to.emplace_back(lp, lq);
    dsu.merge(p, q);
    parent[dsu.leader(p)] = pa;
  }
  int m = to.size();
  int root = m - 1;
  vector<pair<int, int>> size(m);
  auto dfs = [&](auto dfs, int u) -> int {
    if (u >= 0 && u < N) return 1;
    int le = dfs(dfs, to[u].first);
    int ri = dfs(dfs, to[u].second);
    size[u] = {le, ri};
    return le + ri;
  };
  dfs(dfs, root);
  vector<mint> ans(N);
  auto dfs2 = [&](auto dfs2, int u, mint acc) -> void {
    if (u >= 0 && u < N) {
      ans[u] = acc;
      return;
    }
    int sum = size[u].first + size[u].second;
    dfs2(dfs2, to[u].first, mint(size[u].first) / sum + acc);
    dfs2(dfs2, to[u].second, mint(size[u].second) / sum + acc);
  };
  dfs2(dfs2, root, 0);
  rep(i, N) cout << ans[i].val() << " ";
  cout << endl;
}
