## 個人的に必要な用語

- 述語論理
- 集合
- 元
- 半群
- モノイド
- 群
- 可換群、アーベル群
- 環
- 閉じている
- 線形性
- 空間計算量

### 使用例

- max は半群だから操作の取り消しができない
- 自然数は加法について閉じている
- セグ木に乗せるために、半群に単位元を定義してモノイドにする
- セグ木のモノイドの空間計算量はO(N)

## 変数名の意味

- `suf`：suffix。後ろから累積和を取ったもの

## 完全二分木

以下のコードを何も見ずに実装できるようにしたい。

```cpp
auto update = [&](int l, int r, int x) {
  l += N, r += N;
  while (l != r) {
    if (l & 1) operate(l++, x);
    if (r & 1) operate(--r, x);
    l /= 2, r /= 2;
  }
};

auto get = [&](int i) {
  i += N;
  /* 単位元で初期化した変数を用意 */
  while (i) {
    /* 二項演算の結果で変数を更新 */
    i /= 2;
  }
  return ret;
};
```

## multisetの要素の削除

`ms.erase(1)`だと複数の要素が一括で削除される。  
`ms.erase(ms.find(1))`であれば一つの要素だけが削除される。

## 最も簡単な暗号化と復号化

`~`を使う。  
非負整数を暗号化するときに`~v`と書き、複合化するときに`~(~v)`と書く。  
暗号化されているかどうかは`v<0`で判定できる。
