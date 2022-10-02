class Solution {
public:
    unordered_map<int,long long> m;
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> dp(rides.size(),-1);
        sort(rides.begin(),rides.end());
        return recursion(n,rides,0,0,dp);
    }
    long long recursion(int n,vector<vector<int>>& rides,int i,int l,vector<long long>& dp)
    {
        if(i==rides.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        // if(rides[i][0]<l) return recursion(n,rides,i+1,l,dp);
        int end=rides.size()-1,start=i+1,mid,next=end+1;
        while(start<=end) 
        {
            mid=start+(end-start)/2;
            if(rides[mid][0]>=rides[i][1])
            {
                next=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        long long fare=rides[i][1]-rides[i][0]+rides[i][2];
        return dp[i]=max(fare+recursion(n-1,rides,next,rides[i][1],dp),recursion(n,rides,i+1,rides[i][1],dp));
    }
};