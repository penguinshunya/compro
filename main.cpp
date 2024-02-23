#include "library/main.hpp"

#include <atcoder/all>
using namespace atcoder;

int main() {
  int x, y;
  cin >> x >> y;
  if (y - x <= 2 && y - x >= -3) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
  return 0;
}
