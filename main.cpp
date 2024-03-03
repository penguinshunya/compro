#include "library/main.hpp"

void solve() {
  int H, W, N;
  cin >> H >> W >> N;
  auto holes = vector(H + 1, vector(W + 1, 0));
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    holes[a][b] += 1;
  }
  reps(i, H) reps(j, W) {
    holes[i][j] += holes[i - 1][j] + holes[i][j - 1] - holes[i - 1][j - 1];
  }
  i64 ans = 0;
  reps(i, H) reps(j, W) {
    int ok = 0, ng = 3010;
    while (ng - ok != 1) {
      int md = (ok + ng) / 2;
      if (i - md < 0 || j - md < 0) {
        ng = md;
        continue;
      }
      int pi = i - md, pj = j - md;
      int cnt = holes[i][j] - holes[i][pj] - holes[pi][j] + holes[pi][pj];
      if (cnt == 0) ok = md;
      else ng = md;
    }
    ans += ok;
  }
  cout << ans << endl;
}
