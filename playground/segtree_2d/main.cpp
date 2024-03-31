#include "library/main.hpp"

// https://nyaannyaan.github.io/library/data-structure-2d/2d-segment-tree.hpp.html
template <typename T, typename F> struct segtree2d {
  int H, W;
  vector<T> seg;
  const F f;
  const T I;
  int id(int h, int w) { return h * W * 2 + w; }
  segtree2d(int H, int W, F f, const T &I) : f(f), I(I) { init(H, W); }
  void init(int h, int w) {
    H = W = 1;
    while (H < h)
      H <<= 1;
    while (W < w)
      W <<= 1;
    seg.assign(4 * H * W, I);
  }
  void set(int h, int w, const T &x) { seg[id(h + H, w + W)] = x; }
  void build() {
    for (int w = W; w < 2 * W; w++) {
      for (int h = H - 1; h; h--) {
        seg[id(h, w)] = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
      }
    }
    for (int h = 0; h < 2 * H; h++) {
      for (int w = W - 1; w; w--) {
        seg[id(h, w)] = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
      }
    }
  }
  T get(int h, int w) const { return seg[id(h + H, w + W)]; }
  T operator()(int h, int w) const { return get(h, w); }

  void update(int h, int w, const T &x) {
    h += H, w += W;
    seg[id(h, w)] = x;
    for (int i = h >> 1; i; i >>= 1) {
      seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]);
    }
    for (; h; h >>= 1) {
      for (int j = w >> 1; j; j >>= 1) {
        seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);
      }
    }
  }

  T _inner_query(int h, int w1, int w2) {
    T res = I;
    for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
      if (w1 & 1) res = f(res, seg[id(h, w1)]), w1++;
      if (w2 & 1) --w2, res = f(res, seg[id(h, w2)]);
    }
    return res;
  }

  T query(int h1, int w1, int h2, int w2) {
    if (h1 >= h2 || w1 >= w2) return I;
    T res = I;
    h1 += H, h2 += H, w1 += W, w2 += W;
    for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
      if (h1 & 1) res = f(res, _inner_query(h1, w1, w2)), h1++;
      if (h2 & 1) --h2, res = f(res, _inner_query(h2, w1, w2));
    }
    return res;
  }
};

void solve() {
  auto f = [](int x, int y) { return max(x, y); };
  auto I = -INF;
  auto seg = segtree2d(3, 3, f, I);
  seg.set(0, 0, 5);
  seg.set(0, 1, 3);
  seg.set(0, 2, 6);
  seg.set(1, 0, 1);
  seg.set(1, 1, 7);
  seg.set(1, 2, 4);
  seg.set(2, 0, 9);
  seg.set(2, 1, 2);
  seg.set(2, 2, 8);
  seg.build();
  {
    auto res = seg.query(0, 0, 3, 3);
    cout << res << endl;
  }
  {
    auto res = seg.query(0, 0, 2, 2);
    cout << res << endl;
  }
}
