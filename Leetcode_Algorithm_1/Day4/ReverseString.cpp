/*
Problem: https://leetcode.com/problems/reverse-string/

344. Reverse String
Easy

Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Constraints:

    1 <= s.length <= 105
    s[i] is a printable ascii character.

*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();                       //n is total no. of elements in array s
        int start = 0, end = n - 1;             //start is index from begining; end is index from the end
        char temp;

        while(start < end){
            temp = s[start];                    //swapping 
            s[start] = s[end];
            s[end] = temp;
            
            start++;                            //start index incrementing by one
            end--;                              //end index decrementing by one
        }
    }
};

/*
We can also make separate function for swapping.
*/