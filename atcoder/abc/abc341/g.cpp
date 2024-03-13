#include "library/main.hpp"

struct Point {
  i64 x, y;
  Point(i64 x, i64 y) : x(x), y(y) {}
};

void solve() {
  int N;
  cin >> N;
  vector<i64> A(N);
  cin >> A;
  vector<i64> sums(N + 1);
  rep(i, N) sums[i + 1] = sums[i] + A[i];
  vector<Point> st;
  st.emplace_back(N, sums[N]);
  vector<double> ans(N);
  rrep(i, N) {
    auto p = Point(i, sums[i]);
    while (st.size() >= 2) {
      auto a = st[st.size() - 1];
      auto b = st[st.size() - 2];
      a.x -= p.x, a.y -= p.y;
      b.x -= p.x, b.y -= p.y;
      if (a.y * b.x < a.x * b.y) {
        st.pop_back();
      } else {
        break;
      }
    }
    auto a = st[st.size() - 1];
    a.x -= p.x, a.y -= p.y;
    ans[i] = double(a.y) / a.x;
    st.push_back(p);
  }
  rep(i, N) cout << ans[i] << '\n';
}
