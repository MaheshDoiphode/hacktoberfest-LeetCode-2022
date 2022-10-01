// problem==4.Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                merged.push_back(nums1[i]);
                merged.push_back(nums2[j]);
                i++,j++;
            }
            else if(nums1[i] < nums2[j])
            {
                merged.push_back(nums1[i]);
                i++;
            }
            else
            {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        for(; i < nums1.size(); i++)
            merged.push_back(nums1[i]);
        for(; j < nums2.size(); j++)
            merged.push_back(nums2[j]);
        int l = 0, r = merged.size() - 1;
        int mid = l + (r - l)/2;
        if((merged.size()%2) == 0)
            return (double)(merged[mid] + merged[mid+1])/2;
        return merged[mid];
    }
};
