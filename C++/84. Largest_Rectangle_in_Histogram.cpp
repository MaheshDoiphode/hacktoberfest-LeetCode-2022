/*

Problem Link:
https://leetcode.com/problems/largest-rectangle-in-histogram/

*/

class Solution {

private:
    vector<int> findNextSmallerElementIndexes(vector<int> heights, int n) {
        
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = n-1; i >=0; i--) {
            
            int curr = heights[i];
            
            while(s.top() != -1 && heights[s.top()] >= curr) {
                s.pop();
            }
            
            // Adding index of next smaller element to ans
            ans[i] = s.top();
            // Pushing index of curr element to stack
            s.push(i);
            
        }
        
        return ans;
       
    }
    
     vector<int> findPreviousSmallerElementIndexes(vector<int> heights, int n) {
        
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            
            int curr = heights[i];
            
            while(s.top() != -1 && heights[s.top()] >= curr) {
                s.pop();
            }
            
            // Adding index of previous smaller element to ans
            ans[i] = s.top();
            // Pushing index of curr element to stack
            s.push(i);
            
        }
        
        return ans;
       
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> next(n);
        next = findNextSmallerElementIndexes(heights, n);
        
        vector<int> prev(n);
        prev = findPreviousSmallerElementIndexes(heights, n);
        
        int area = INT_MIN;
        for(int i = 0; i < n; i++) {
            
            int length = heights[i];
            
            // handling negative breadth
            if (next[i] == -1)
                next[i] = n;
            
            int breadth = next[i] - prev[i] - 1;
            
            int newArea = length * breadth;
            
            area = max(area, newArea);
            
        }
        
        return area;
        
    }
};
