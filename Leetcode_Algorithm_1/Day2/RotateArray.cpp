/*
Problem: https://leetcode.com/problems/rotate-array/

189. Rotate Array
Medium

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

*/

class Solution {
public:
    void reverse(vector<int> &nums, int start, int end){        //reverses the part of array from start to end
        int i, j, temp;
        for(i = start, j = end; i < j; i++, j--){
            temp = nums[i];                                     //swapping value of nums[i] and nums[j]
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    void rotate(vector<int>& nums, int k) {                     //nums = [1,2,3,4,5,6,7], k = 3
        int n = nums.size();

        if(k >= n)                                              //taking mod if k>n. Otherwise heap buffer overflow error will occur
            k %= n;
        
        if(k == 0) return;                                      //k=0 means no rotation required
        
        reverse(nums, 0, n - 1);                                //reverse complete array      nums = [7,6,5,4,3,2,1]
        reverse(nums, 0, k - 1);                                //reverse first k elements    nums = [5,6,7,4,3,2,1]
        reverse(nums, k, n - 1);                                //reverse remaining elements  nums = [5,6,7,1,2,3,4]
    }
};

/*
Follow up:
Could you do it in-place with O(1) extra space?
Yes, This solution rotates the array using O(1) space
*/