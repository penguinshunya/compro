use std::collections::{HashMap, HashSet};

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
    // HashSet の使い心地はどうか？
    {
        let mut st: HashSet<i32> = HashSet::new();
        for i in vec![1, 2, 2] {
            st.insert(i);
        }
        for i in vec![1, 2, 3] {
            println!("exists: {}", st.contains(&i));
        }
        println!("len: {}", st.len());
    }
}
