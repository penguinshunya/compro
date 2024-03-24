#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N;
  cin >> N;
  string S, T;
  cin >> S >> T;
  int M = S.size();
  auto pos = vector(26, vector<int>());
  for (int i = 0; i < M; i++) {
    int c = S[i] - 'a';
    pos[c].push_back(i);
  }
  long long left = 0, right = 1001001001001001001ll;
  while (right - left != 1) {
    long long mid = (left + right) / 2;
    long long cur = 0;
    bool ok = true;
    for (auto _c : T) {
      if (cur == N * M) {
        ok = false;
        break;
      }
      long long rem = mid;
      int c = _c - 'a';
      int pn = pos[c].size();
      if (pn == 0) {
        ok = false;
        break;
      }
      int i = cur % M;
      int l = lower_bound(pos[c].begin(), pos[c].end(), i) - pos[c].begin();
      if (l + rem <= pn) {
        cur = cur - i + pos[c][l + rem - 1] + 1;
        continue;
      }
      rem -= pn - l;
      cur = cur - i + M;
      long long rem_n = N - cur / M;
      if (rem_n * pn < rem) {
        ok = false;
        break;
      }
      long long ne = (rem - 1) / pn;
      rem -= ne * pn;
      cur += ne * M + pos[c][rem - 1] + 1;
    }
    if (ok) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;
  return 0;
}
