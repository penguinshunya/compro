## 問題を解く上で意識すべきこと

- 問題文を正しく理解する
- 場合分けを行う
- 計算量を見積もってから実装しはじめる
- 添字についてしっかりと考えてから実装しはじめる
- 実装上の工夫をする
  - 全列挙した配列を用意してネストを減らす
  - 構造体や関数を定義する
    - `for (auto [x1, y1, z1]: lst)` は良くない
- 何かを固定する
  - 平面走査
- 別の問題に言い換える
- 解けなかったとき、[解けなかった理由](./docs//impediment.md)について考える

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

## 他のドキュメントへのリンク

- [Tips](./docs/tips.md)
- [確率論](./docs/probability_theory.md)
