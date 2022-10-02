// Time Complexity :- O(N * K)
// Space Complexity :- O(N * K)

class Solution {
public:
    
    // if state == true => we have to buy the stock
    
    // if state == false => we have to sell the stock
    
    // initially state will be true, b/c first we have to buy the stock 
    
    // declare a dp
    
    int dp[1005][105][2];
    
    int dfs(vector<int>& prices, int i, int n, int k, bool state)
    {
        // base case
        
        // if there is no. transactions remaining
        
        if(k < 0)
            return 0;
        
        // if there is no. element remaining
        
        if(i == n)
        {
            return 0;
        }
        
        // if already calculated
      
        if(dp[i][k][state] != -1)
            return dp[i][k][state];
        
        int maxi = INT_MIN;
        
        // we have two option either include the curr_element or exclude
        
        // inclusion part (either we buying or selling depends on state)
        
        if(state)
        {
            maxi = max(maxi, - prices[i] + dfs(prices, i + 1, n, k - 1, !state));
        }
        else
        {
            maxi = max(maxi, prices[i] + dfs(prices, i + 1, n, k, !state));
        }
        
        // exclusion part
        
        maxi = max(maxi, dfs(prices, i + 1, n, k, state));
        
        // store the res then return 
        
        return dp[i][k][state] = maxi;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        // initialize dp with -1
        
        memset(dp, -1, sizeof(dp));
        
        // call dfs
        
        return dfs(prices, 0, n, k, true);
    }
};
