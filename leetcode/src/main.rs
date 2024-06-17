use std::collections::HashMap;

fn main() {
    // HashMap::insert は既存の値を上書きするか？
    {
        let mut mp: HashMap<i32, usize> = HashMap::new();
        let v = vec![1, 2, 2];
        for (i, x) in v.into_iter().enumerate() {
            mp.insert(x, i);
        }
        print!("{{ ");
        for (k, v) in mp.into_iter() {
            print!("{}:{} ", k, v); // { 1:0 2:2 }
        }
        println!("}}");
    }
}
