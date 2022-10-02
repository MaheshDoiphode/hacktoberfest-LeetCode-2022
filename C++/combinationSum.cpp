class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int>v;
        int n=0;
        helper(n,candidates,target,ans,v);
        return ans;
    }
    
    void helper(int n,vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>v){
        if(n>=candidates.size() or target<0)return;
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        v.push_back(candidates[n]);
        helper(n,candidates,target-candidates[n],ans,v);
        v.pop_back();
        helper(n+1,candidates,target,ans,v);
        
    }
    
    
    
    
};
