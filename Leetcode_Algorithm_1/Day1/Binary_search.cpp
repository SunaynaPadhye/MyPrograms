/*
Problem: https://leetcode.com/problems/binary-search/

704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;         //Use this method otherwise value of mid may overflow
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

/*
This is main fuction for input-output (not needed for submitting on leetcode).
Use this to make changes and learn from the code.

int main(){
    int target;
    int n, i;

    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);

    cout << "\nEnter array elements: ";
    for(i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "\nEnter target element: ";
    cin >> target;

    Solution obj;
    cout << obj.search(nums, target);

    return 0;
}

*/