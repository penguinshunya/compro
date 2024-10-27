use proconio::input;

type Mint = ac_library::ModInt1000000007;

fn main() {
    input! {n: usize, b: usize, k: usize, c: [usize; k]}
    let mut pow = vec![0; 61];
    pow[0] = 10;
    for i in 1..=60 {
        pow[i] = pow[i - 1] * pow[i - 1] % b;
    }
    let mut dp = vec![vec![Mint::new(0); b]; 61];
    for &c in c.iter() {
        dp[0][c % b] += 1;
    }
    for i in 0..60 {
        for j in 0..b {
            for k in 0..b {
                let l = (j * pow[i] + k) % b;
                let t = dp[i][j] * dp[i][k];
                dp[i + 1][l] += t;
            }
        }
    }
    let mut ans = vec![Mint::new(0); b];
    ans[0] = 1.into();
    for i in 0..=60 {
        if n >> i & 1 == 0 {
            continue;
        }
        let mut nans = vec![Mint::new(0); b];
        for j in 0..b {
            for k in 0..b {
                let l = (j * pow[i] + k) % b;
                nans[l] += ans[j] * dp[i][k];
            }
        }
        ans = nans;
    }
    println!("{}", ans[0]);
}
