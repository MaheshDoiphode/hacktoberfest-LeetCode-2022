# Dynamic Programming is being used and there are two ways to solve this problem.

# 1. Using 2D Array

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target, n = sum(nums), len(nums)
        if target & 1: return False #target or the total sum is odd, so we return false.
        target >>= 1 #divide target by 2
        row, col = len(nums)+1, target+1
        memo = [[False for i in range(col)] for j in range(row)]
        memo[0][0] = True
        for i in range(1, row):
            for j in range(col):
                if j-nums[i-1] >= 0:
                    memo[i][j] = memo[i-1][j] or memo[i-1][j-nums[i-1]]
                else:   
                    memo[i][j] = memo[i-1][j]  
                
        return memo[row-1][col-1]

# 2. Using 1D Array

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target, n = sum(nums), len(nums)
        if target & 1: return False #target or the total sum is odd, so we return false.
        target >>= 1 #divide target by 2
        dp = [True] + [False]*target #create a list with len = target + 1
        #dp array will represent wether a sum(index of dp) is possible with the given nums or not.
        for num in nums:
            for i in range(len(dp)-1, -1, -1):
                dp[i] = dp[i] or (i >= num and dp[i-num])
                #this loop works from top to bottom. If we run from bottom to top then it fails.
        return dp[-1]
      
