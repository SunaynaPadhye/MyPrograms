/*
Problem: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/

Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]

 

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1

 
Follow up: Could you minimize the total number of operations done?
   Hide Hint #1  
In-place means we should not be allocating any space for extra array. But we are allowed to modify the existing array. However, as a first step, try coming up with a solution that makes use of additional space. For this problem as well, first apply the idea discussed using an additional array and the in-place solution will pop up eventually.
   Hide Hint #2  
A two-pointer approach could be helpful here. The idea would be to have one pointer for iterating the array and another pointer that just works on the non-zero elements of the array.
*/

class Solution {
public:
    void swap(vector<int>& nums, int x, int y){
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int z = 0;                  //index of first zero in array
        int y = 0;                  //index of first non zero in array
        int n = nums.size();
        
        while(z < n){
            if(nums[z] != 0){
                z++;
            }
            else break;
        }
        y = z;
        
        while(y < n){
            if(nums[y] != 0 && nums[z] == 0){
                swap(nums, y, z);
                z++;
            }
            while(y < n){
            if(nums[y] == 0){
                y++;
            }
            else break;
         } 
            
        }
    }
};