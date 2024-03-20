#include "library/main.hpp"

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

void solve() {
  auto comb = Combination<mint>(1000000);
  int H, W, K;
  cin >> H >> W >> K;
  mint ans = 0;
  reps(h, H) reps(w, W) {
    mint acc = 0;
    rep(k, 16) {
      int u = __builtin_popcount(k & 3);
      int v = __builtin_popcount(k & 12);
      if (h - u < 0 || w - v < 0) continue;
      acc += comb((h - u) * (w - v), K) * (((u + v) & 1) ? -1 : 1);
    }
    ans += acc * h * w * (H - h + 1) * (W - w + 1);
  }
  ans /= comb(H * W, K);
  cout << ans.val() << endl;
}
