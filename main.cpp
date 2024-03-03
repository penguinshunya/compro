#include "library/main.hpp"

void solve() {
  int N, M;
  cin >> N >> M;
  auto mat = vector(N, vector(N, INF));
  rep(i, N) mat[i][i] = 0;
  rep(i, M) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    mat[u][v] = w;
  }
  rep(k, N) rep(i, N) rep(j, N) {
    if (mat[i][k] == INF || mat[k][j] == INF) continue;
    amin(mat[i][j], mat[i][k] + mat[k][j]);
  }
  auto dp = vector(1 << N, vector(N, INF));
  rep(i, N) dp[1 << i][i] = 0;
  rep(s, 1 << N) rep(u, N) rep(v, N) {
    if (dp[s][u] == INF || mat[u][v] == INF) continue;
    if (s >> v & 1) continue;
    amin(dp[s | (1 << v)][v], dp[s][u] + mat[u][v]);
  }
  int ans = INF;
  rep(i, N) amin(ans, dp[(1 << N) - 1][i]);
  if (ans == INF) {
    cout << "No" << endl;
    return;
  }
  cout << ans << endl;
}
