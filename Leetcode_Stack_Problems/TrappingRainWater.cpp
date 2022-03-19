/*
Problem: https://leetcode.com/problems/trapping-rain-water/

42. Trapping Rain Water
Hard

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 
Constraints:

    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105


*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0, right = n - 1;
        int leftmax = 0, rightmax = 0;
        
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= leftmax)
                    leftmax = height[left];
                else ans += leftmax - height[left]; 
                left++;
            }
            else{
                if(height[right] >= rightmax)
                    rightmax = height[right];
                else ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};

/*
References: 
https://takeuforward.org/data-structure/trapping-rainwater/
https://www.youtube.com/watch?v=m18Hntz4go8
*/