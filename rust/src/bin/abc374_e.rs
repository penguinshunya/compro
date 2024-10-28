use num::integer::div_ceil;
use proconio::input;

fn main() {
    input! {n: usize, x: i64}
    input! {qu: [(i64, i64, i64, i64); n]}
    let mut ac = 0;
    let mut wa = 1e18 as i64;
    while wa - ac > 1 {
        let wj = (wa + ac) / 2;
        let mut xsum: i64 = 0;
        for &(a, p, b, q) in qu.iter() {
            let mut mi = i64::MAX;
            for i in 0..=b {
                let j = if wj < a * i {
                    0
                } else {
                    div_ceil(wj - a * i, b)
                };
                mi = mi.min(p.saturating_mul(i).saturating_add(q.saturating_mul(j)));
            }
            for j in 0..=a {
                let i = if wj < b * j {
                    0
                } else {
                    div_ceil(wj - b * j, a)
                };
                mi = mi.min(p.saturating_mul(i).saturating_add(q.saturating_mul(j)));
            }
            xsum = xsum.saturating_add(mi);
        }
        if xsum <= x {
            ac = wj;
        } else {
            wa = wj;
        }
    }
    println!("{}", ac);
}
