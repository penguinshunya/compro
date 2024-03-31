#include "library/main.hpp"

template <typename T> struct Compress {
  vector<T> v;
  Compress() {}
  Compress(vector<T> v) : v(v) { build(); }
  void insert(T x) { v.push_back(x); }
  void build() {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
  }
  int get(T x) { return lower_bound(all(v), x) - v.begin(); }
  int size() { return v.size(); }
};

void solve() {
  vector<int> v = {1, 3, 2, 2, 5, 3, 4, 100000};
  auto com = Compress(v);
  assert(com.size() == 6);
  assert(com.get(100000) == 5);
}
