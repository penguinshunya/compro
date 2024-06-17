// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut p = &mut dummy;
        let mut curry = 0;
        let mut l1 = l1;
        let mut l2 = l2;
        while l1.is_some() || l2.is_some() || curry != 0 {
            let sum = curry
                + l1.clone().unwrap_or(Box::new(ListNode::new(0))).val
                + l2.clone().unwrap_or(Box::new(ListNode::new(0))).val;
            curry = sum / 10;
            p.next = Some(Box::new(ListNode::new(sum % 10)));
            if let Some(ref mut next_p) = p.next {
                p = next_p;
            }
            if let Some(x) = l1 {
                l1 = x.next;
            }
            if let Some(x) = l2 {
                l2 = x.next;
            }
        }
        return dummy.next;
    }
}
