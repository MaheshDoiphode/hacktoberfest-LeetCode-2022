class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        m, n = len(nums1), len(nums2)
        
        left_size = (m + n + 1) // 2
        start = 0
        end = m
        is_even = ((m + n) % 2) == 0
        while start <= end:
            a_part = (start + end) // 2
            b_part = left_size - a_part
            
            aleftmax = float("-inf") if a_part == 0 else nums1[a_part - 1]
            arightmin = float("inf") if a_part == m else nums1[a_part]
            bleftmax = float("-inf") if b_part == 0 else nums2[b_part - 1]
            brightmin = float("inf") if b_part == n else nums2[b_part]
            
            if aleftmax <= brightmin and bleftmax <= arightmin:
                if not is_even:
                    return max(aleftmax, bleftmax)
                else:
                    return (max(aleftmax, bleftmax) + min(arightmin, brightmin))/ 2
            elif aleftmax > brightmin:
                end = a_part - 1
            elif bleftmax > arightmin:
                start = a_part + 1
