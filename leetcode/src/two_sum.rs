use std::collections::HashMap;

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut mp: HashMap<i32, i32> = HashMap::new();
    for (i, x) in nums.iter().enumerate() {
        let rem = target - x;
        if mp.contains_key(&rem) {
            return vec![mp[&rem], i as i32];
        }
        mp.insert(*x, i as i32);
    }
    return vec![];
}
