// 1482. Minimum Number of Days to Make m Bouquets
// You are given an integer array bloomDay, an integer m and an integer k.
// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

// Example 1:
// 
// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int b : bloomDay) {
            max = Math.max(max, b);
            min = Math.min(min, b);
        }
        int n = bloomDay.length;
        
        if (n < m * k) return -1;
        
        while (min < max) {
            int mid = (min + max) / 2;
            int cnt = 0, adj = 0;
            for (int b : bloomDay) {
                if (b > mid) adj = 0;
                else {
                    adj++;
                    if (adj == k) {
                        adj = 0;
                        cnt++;
                    }
                }
                if (cnt >= m) break;
            }
            
            if (cnt < m) min = mid + 1;
            else max = mid;
        }
        return min;
    }
}
