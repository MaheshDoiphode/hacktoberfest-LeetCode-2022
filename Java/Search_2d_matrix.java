//problem link :-https://leetcode.com/problems/search-a-2d-matrix/    


class Solution {
    public boolean searchMatrix(int[][] matrix, int target){
        
        if(target<matrix[0][0])
        {
            return false;
        }
    
        int m=matrix.length;
        int n=matrix[0].length;
        
        if(target>matrix[m-1][n-1])
        {
            return false;
        }
        
        int low=0;
        int high=m-1;
        int mid=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(matrix[mid][0]>target)
            {
                high=mid-1;
            }
            else if(matrix[mid][0]<target)
            {
                low=mid+1;
            }
            else if(matrix[mid][0]==target)
            {
                return true;
            }
        }
    
        low=0;
        int row=high;
        high=n-1;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            if(matrix[row][mid]==target)
            {
                return true;
            }
            
            else if(matrix[row][mid]>target)
            {
                high=mid-1;
            }
            
            else if(matrix[row][mid]<target)
            {
                low=mid+1;
            }
        }
        
        return false;

        
    }
}
