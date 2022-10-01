//problem==70(Climbing Stairs)
// topic: dynamic programming
// difficulty level:easy


class Solution {
public:
int climbStairs(int n) {
// if(n<=3){
// return n;
// }
// return climbStairs(n-1) + climbStairs(n-2);
int arr[45];

    arr[0] = 1; 
    arr[1] = 2;
    for(int i=2; i<45; i++){
        arr[i] = arr[i-1]+arr[i-2];
    } 
    return arr[n-1];
}
};
