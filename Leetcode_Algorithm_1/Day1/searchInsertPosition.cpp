/*
Problem: https://leetcode.com/problems/search-insert-position/

35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low, high, mid;
        low = 0;
        high = nums.size() - 1;
        
        while(low <= high){
            mid = low + (high - low)/2;                 //Use this method otherwise value of mid may overflow
            
            if(nums[mid] == target)                     //target found at mid
                return mid;
            else if(nums[mid] < target)                 //shift towards right subarray
                low = mid + 1;
            else if(nums[mid] > target)                 //shift towards left subarray
                high = mid - 1;
        }
        
        // target not found
        if(nums[mid] < target)                          //insertion of target after mid
            return mid + 1;
        else return mid;                                //insertion of target at mid
    }
};

/*
This solution is an implementation of binary search algoritm
*/