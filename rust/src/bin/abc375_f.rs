use itertools::{iproduct, Itertools};
use proconio::{input, marker::Usize1};

fn main() {
    input! {n: usize, m: usize, q: usize}
    input! {abc: [(Usize1, Usize1, usize); m]}
    let mut qs = vec![];
    let mut delete_edges = vec![];
    for _ in 0..q {
        input! {t: u8}
        if t == 1 {
            input! {i: Usize1}
            qs.push((1, i, 0));
            delete_edges.push(i);
        } else {
            input! {x: Usize1, y: Usize1}
            qs.push((2, x, y));
        }
    }
    let mut dp = vec![vec![1e18 as usize; n]; n];
    for i in 0..n {
        dp[i][i] = 0;
    }
    for (i, &(a, b, c)) in abc.iter().enumerate() {
        if delete_edges.contains(&i) {
            continue;
        }
        dp[a][b] = c;
        dp[b][a] = c;
    }
    for (k, i, j) in iproduct!(0..n, 0..n, 0..n) {
        dp[i][j] = (dp[i][k] + dp[k][j]).min(dp[i][j]);
    }
    let mut ans = vec![];
    for &(t, x, y) in qs.iter().rev() {
        if t == 2 {
            ans.push(dp[x][y]);
            continue;
        }
        let (a, b, c) = abc[x];
        for (i, j) in iproduct!(0..n, 0..n) {
            dp[i][j] = (dp[i][a] + c + dp[b][j]).min(dp[i][j]);
            dp[i][j] = (dp[i][b] + c + dp[a][j]).min(dp[i][j]);
        }
    }
    ans.reverse();
    println!(
        "{}",
        ans.iter()
            .map(|&v| if v == 1e18 as usize { -1 } else { v as i64 })
            .join("\n")
    );
}
