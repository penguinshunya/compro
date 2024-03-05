## 問題を解く上で意識すべきこと

- 問題文を正しく理解する
- 場合分けを行う
  - [場合の数は漏れなく重複なく](https://www.youtube.com/watch?v=8E9awm82Ij0)
- 別の問題に言い換える
- 何かを固定する
- 添字についてきちんと決めてから実装しはじめる

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

### 変数名の意味

- `suf`：suffix。後ろから累積和を取ったもの

## Tips

### multisetの要素の削除

`ms.erase(1)`だと複数の要素が一括で削除される。  
`ms.erase(ms.find(1))`であれば一つの要素だけが削除される。

### 最も簡単な暗号化と復号化

`~`を使う。  
非負整数を暗号化するときに`~v`と書き、複合化するときに`~(~v)`と書く。  
暗号化されているかどうかは`v<0`で判定できる。

### 相反する二つの操作を一つの関数にまとめる

空の多重集合があり、ここに整数を追加したり削除したりする。  
たまに「今何種類の整数があるか」というクエリが飛んでくる。  
このようなときに次の関数を用意する。

```cpp
map<int, int> mp;

auto operate = [&](int x, int d) {
  mp[x] += d;
  if (mp[x] == 0) mp.erase(x);
};
```

すると、追加と削除の操作をそれぞれ次のように書ける。

```cpp
operate(100, 1);
operate(100, -1);
```

この実装パターンは、相反する二つの操作を一箇所にまとめられる点で優れている。  
上の例のような単純な操作であれば恩恵は少ないが、操作が複雑になるにつれて恩恵が増していく。  

### 完全二分木

完全二分木の区間更新と一点取得は次のようにシンプルに実装できる。

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

### $n$ 人を区別のない $k$ 個以下のグループに分ける場合の数（ベル数）

|人数|場合の数|
|-|-|
|1|1|
|2|2|
|3|5|
|4|15|
|5|52|
|6|203|
|7|877|
|8|4,140|
|9|21,147|
|10|115,975|
|11|678,570|
|12|4,213,597|
|13|27,644,437|
|14|190,899,322|
|15|1,382,958,545|

<details>
<summary>自然とベル数になる全探索のコード</summary>

```cpp
const int N = 10;
int cnt = 0;

vector<vector<int>> v;
auto rec = [&](auto rec, int x) -> void {
  if (x == N) {
    cnt++;
    return;
  }
  for (int i = 0; i < v.size(); i++) {
    v[i].push_back(x);
    rec(rec, x + 1);
    v[i].pop_back();
  }
  v.push_back({x});
  rec(rec, x + 1);
  v.pop_back();
};
rec(rec, 0);

cout << cnt << endl; //=> 115975
```
</details>

### ビット操作

|関数|説明|
|-|-|
|`__builtin_popcount`|ビットの 1 の数を返す|
|`bit_width`|整数のビット幅を返す。引数はunsigned|

### ビット集合の部分集合の列挙

計算量を $O(4^N)$ から $O(3^N)$ に落とすときに必要。

```cpp
// 昇順
for (int t = 0;; t = (t - s) & s) {
  if (t == s) break;
}

// 降順
for (int t = s;; t = (t - 1) & s) {
  if (t == 0) break;
}
```

### 整数から文字列への変換

`to_string`を使う。  
以下のコードは`to_string`を用いた回文判定のコード。

```cpp
long long x = 1334996994331ll;
string s = to_string(x);
string t = s;
reverse(t.begin(), t.end());
cout << (s == t ? "Yes" : "No") << endl;  //=> Yes
```

### 9桁の素数

ローリングハッシュの除数として利用する。

```cpp
const vector<int> primes = {
  998244353, 998244389, 998244391, 998244397, 998244407,
  998244431, 998244433, 998244473, 998244487, 998244493,
  998244521, 998244523, 998244529, 998244601, 998244617,
  998244619, 998244631, 998244649, 998244673, 998244677,
  998244679, 998244707, 998244713, 998244749, 998244761,
  998244787, 998244799, 998244803, 998244839, 998244853,
};
```

### mask関数を定義する

複雑なビット演算をひとつの式に書かなくて済むので理解しやすくなる。

```c++
// o
mask = (1 << N) - 1
(t | (t << x)) & mask

// x
(t | (t << x)) & ((1 << N) - 1)
```

## 解けなかった理由

#### 条件を満たす数列を数え上げるとき、同じ選択をした場合は同じ状態に遷移しなければならない。

<details>

- 部分和問題では各 $i$ について2つの状態に遷移するが、これは $x$ か $0$ のいずれかを選択しているからである
- 「 $x$ を選択したが、それは条件とは無関係であるため、選ばれたときと区別するために別の状態に遷移する」これは許されない。どちらも $x$ が選ばれた点で変わらないのだから同じ状態に遷移しなければならない。でないと、重複して数え上げてしまう恐れがある
</details>

#### 包除原理の誤解

包除原理は、「1つ以上含む場合の数から、2つ以上含む場合の数を引き、3つ以上含む場合の数を足し、...」というものではなく、「1つだけに注目したときの場合の数から、2つだけに注目したときの場合の数を引き、3つだけに注目したときの場合の数を足し、...」というものである。
