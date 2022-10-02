/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
       if(k<=1 || head==null || head.next == null)
            return head;
            ListNode current = head;
            ListNode prev = null;
        while(true){

            ListNode last = prev;
            ListNode newEnd = current;
            // reverse the list
            ListNode newPresent = current;
            for(int i = 0; newPresent != null && i < k - 1; i++){
                newPresent = newPresent.next;
            }

            if(newPresent == null){
                break;
            }

            ListNode next = current.next;
            for (int i = 0; current != null && i < k; i++) {
                
                current.next = prev;
                prev = current;
                current = next;
                if (next != null)
                    next = next.next;
            }
            if (last != null) {
                last.next = prev;
            } else {
                head = prev;
            }
            newEnd.next = current;
            if(current == null)
                break;
            prev = newEnd;
        }

        return head;
    }
}
