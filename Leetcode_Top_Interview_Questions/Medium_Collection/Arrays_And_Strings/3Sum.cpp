/*
Problem: https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/

3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:

Input: nums = []
Output: []

Example 3:

Input: nums = [0]
Output: []

Constraints:

    0 <= nums.length <= 3000
    -105 <= nums[i] <= 105


*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int i, j, k;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(i = 0; i<n; i++){
            j = i+1, k = n-1;
            while(j < n && j < k){
                if(nums[j] + nums[k] == -nums[i]){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(k!=0 && nums[k] == nums[k-1])
                        k--;
                    k--;
                    while(j!=n-1 && nums[j] == nums[j+1])
                        j++;
                    j++;
                }
                else if(nums[j] + nums[k] > -nums[i]){
                    while(k!=0 && nums[k] == nums[k-1])
                        k--;
                    k--;
                }
                else{
                    while(j!=n-1 && nums[j] == nums[j+1])
                        j++;
                    j++;
                }
            }
            while(i!=n-1 && nums[i] == nums[i+1])
                i++;
        }
        
        for(auto triplets: ans){
            sort(triplets.begin(), triplets.end());
        }
                   
        return ans;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/