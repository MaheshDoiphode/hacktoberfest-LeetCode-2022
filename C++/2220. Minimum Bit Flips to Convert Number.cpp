/*
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

*/

// this is an Bit Manipulation question , it has a label of easy on leetcode 
// If someone who is good at the basics of bit manipulation can surely try this question on Leetcode
// finding difficulty in solving it then , you can refer to this solution provided below.

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int k=start^goal; // This basically calculating the bit representation of the bits that are changed.
        int count=0;      // setting the count variable to zero
        while(k!=0){
            if(k&1!=0) count++;  // here we take the and of the k number with 1 so to check if the last bit encountered till now is 1 or not if one then increement it by one or dont increement the count.
            k=k>>1;              // in here we right shift the bits of the k by one. if initially if it is 1001 after right shift by one it would be 0100 the bit at the lsb topples of or removed or shifted in this operation.
        }
        return count;            // here we return the value of the count.
    } 
};