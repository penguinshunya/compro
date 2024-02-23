#include "library/main.hpp"

void solve() {
  Vec2 a, b, c;
  cin >> a >> b >> c;
  while (!(b.x < c.x && b.y <= c.y)) {
    a = a.rotate90(), b = b.rotate90(), c = c.rotate90();
  }
  b -= a, c -= a, a -= a;
  if (b.y == c.y) {
    i64 ans = (b + Vec2(-1ll, 0ll)).manhattan() + b.manhattan(c);
    ans += (b.x < 0 && b.y == 0) ? 2 : 0;
    cout << ans << endl;
  } else {
    i64 ans = min((b + Vec2(-1ll, 0ll)).manhattan(),
                  (b + Vec2(0ll, -1ll)).manhattan());
    ans += b.manhattan(c) + 2;
    cout << ans << endl;
  }
}
