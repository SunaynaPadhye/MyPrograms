/*
Problem: https://leetcode.com/problems/squares-of-a-sorted-array/

977. Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);                             //result vector will hold squares in sorted order
        
        int beg = 0, end = n-1, i, j;                   //beg is index moving from left to right, end is index moving from right to left
        for(i = n-1; i>=0, beg <= end; i--){            
            if(abs(nums[beg]) > abs(nums[end])){
                res[i] = nums[beg] * nums[beg];
                beg++;
            }
            else{
                res[i] = nums[end] * nums[end];
                end--;
            }   
        }
        return res;
    }
};

/*
This solves the problem in one iteration i.e. O(n) time complexity.
We are using another vector of same size i.e. O(n) space complexity.

beg and end index will start traversing from opposite sides till they cross each other, checking everytime which absolute value is greater.
It is squared and saved in vector res from the end. The particular index pointer is then moved and again the two values are checked. 
Thus, filling the result vector.
*/