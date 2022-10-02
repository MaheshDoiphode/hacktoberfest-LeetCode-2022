// 561. Array Partition
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int i=0,sum=0;
        sort(nums.begin(),nums.end());
        while(i<nums.size())
        {
            sum += min(nums[i],nums[i+1]);
            i+=2;
        }
        return sum;
    }
};
