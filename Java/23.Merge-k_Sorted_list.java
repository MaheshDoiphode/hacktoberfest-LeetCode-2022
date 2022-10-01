
/*
23. Merge k Sorted Lists
Hard

14302

533

Add to List

Share
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
 */

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        
        int min=Integer.MAX_VALUE,idx=0, flag=0, k=lists.length;
        if (k==0) return null;
        
        ListNode dummy = new ListNode(0);
        ListNode cur=dummy;
        while(flag<k){
            for (int i=0; i<k; i++){
                if (lists[i]!=null && lists[i].val<min) {
                    min=lists[i].val;
                    idx=i;
                }
            }
            if (lists[idx]!=null) {
                lists[idx]= lists[idx].next;
            }
            if (lists[idx]==null) {
                flag++;
            }
            if (min!=Integer.MAX_VALUE){
                cur.next=new ListNode(min);
                min=Integer.MAX_VALUE;
                cur=cur.next;
            }
        }
        return dummy.next;
    }
}