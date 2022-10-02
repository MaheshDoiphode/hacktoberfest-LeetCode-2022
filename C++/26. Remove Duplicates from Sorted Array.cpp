class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int index = 0, value = -500;
        
        for (int i=0;i<n;i++) {
            if (nums[i] != value) {
                nums[index++] = nums[i];
                value = nums[i];
            }
        }
        
        return index;
    }
};