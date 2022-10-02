class Solution {
public:


int findMy_Ans(int low , int high , vector<int> &arr  , int target){

    if(low > high){
        return -1; 
    }

    int mid = (low+high)/2;

    if(arr[mid] == target){
        return mid;
    }

    else if(target > arr[mid]){
        low = mid+1;
    }

    else{
        high = mid-1;
    }

    return findMy_Ans(low , high , arr  , target);


}



    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ansVec;

        int ans = findMy_Ans(0 , nums.size()-1 , nums  , target);


            int st= ans;
            int end= ans;

            while(st-1 >=0 && nums[st-1] == target){
                st--;
            }

            while(end+1 <nums.size() && nums[end+1] == target){
                end++;
            }


        ansVec.push_back(st);
        ansVec.push_back(end);
        

        return ansVec;


    }
};

