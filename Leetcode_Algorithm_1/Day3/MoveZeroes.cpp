/*
Problem: https://leetcode.com/problems/move-zeroes/

283. Move Zeroes
Easy

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

*/

class Solution {
public:
    void swap(vector<int>& nums, int x, int y){             //Swaps two numbers of array
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int z = 0;                  //index of first zero in array
        int y = 0;                  //index of first non-zero in array
        int n = nums.size();
        
        while(z < n){                       //to get initial value of first occurance of zero
            if(nums[z] != 0){
                z++;
            }
            else break;
        }
        y = z;                              //to optimize and start searching non zero elements from z onwards
        
        while(y < n){                       
            if(nums[y] != 0 && nums[z] == 0){           //pair swapped and z moves forward
                swap(nums, y, z);
                z++;
            }

            while(y < n){                               //next non-zero element index in y
                if(nums[y] == 0){
                    y++;
                }
                else break;
            }    
        }
    }
};

/*
This solution has two pointers: 
z is index of first zero element from left.
y is index of first non-zero element from left.
Once positioned, they are swapped and z is incremented. Again nex non-zero element is found and value of y is assigned with it.
When y becomes equal to n i.e. there are no non-zero elements left after zero elements, the program terminates.
*/