/*
Problem Statement
Given n non-negative integers a1, a2, …, an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

Constraints:
n = height.length
2 <= n <= 3 * 104
0 <= height[i] <= 3 * 104
Examples
Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (between 8 and 7 )the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2 
*/





public class ContainerWithMostWater {

    public int maxArea(int[] height) {
        // Maximum area will be stored in this variable
        int maximumArea = Integer.MIN_VALUE;
        // Left and right pointers
        int left = 0;
        int right = height.length - 1;
        // Loop until left and right meet
        while (left < right) {
            // Shorter pole/vertical line
            int shorterLine = Math.min(height[left], height[right]);
            // Update maximum area if required
            maximumArea = Math.max(maximumArea, shorterLine * (right - left));
            // If there is a longer vertical line present
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maximumArea;
    }
}
