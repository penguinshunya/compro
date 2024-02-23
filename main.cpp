#include "library/main.hpp"

#include <atcoder/all>
using namespace atcoder;

void solve() {
  Vec2 a, b, c;
  cin >> a >> b >> c;
  while (!(b.x < c.x && b.y <= c.y)) {
    a = a.rot90(), b = b.rot90(), c = c.rot90();
  }
  b -= a, c -= a, a -= a;
  if (b.y == c.y) {
    i64 ans = (b + Vec2<i64>(-1, 0)).manhattan() + b.manhattan(c);
    ans += (b.x < 0 && b.y == 0) ? 2 : 0;
    cout << ans << endl;
  } else {
    i64 ans = min((b + Vec2<i64>(-1, 0)).manhattan(),
                  (b + Vec2<i64>(0, -1)).manhattan());
    ans += b.manhattan(c) + 2;
    cout << ans << endl;
  }
}
