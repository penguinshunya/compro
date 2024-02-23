#include "library/main.hpp"
#include <atcoder/all>
using namespace atcoder;

void solve() {
  auto [x, y] = extgcd(206, 85);
  cout << x << " " << y << endl;
}
