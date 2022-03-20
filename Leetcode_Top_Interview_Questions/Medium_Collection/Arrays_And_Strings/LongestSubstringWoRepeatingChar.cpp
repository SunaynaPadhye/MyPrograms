/*
Problem: https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/779/

Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 
Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, curLength = 0;
        int st = 0, e = 0;
        
        vector<string> subs;
        vector<bool> al(256, false);
        
        while(e < s.length()){
            if(al[s[e]]){
                al[s[st]] = false;
                st++;
            }
            else{
                al[s[e]] = true;
                curLength = e-st+1;
                
                if(curLength == maxLength)
                    subs.push_back(s.substr(st, curLength));
                if(curLength > maxLength){
                    maxLength = curLength;
                    subs.clear();
                    subs.push_back(s.substr(st, curLength));            //or use maxLength
                }
                e++;
            }
        }
        // for(int i = 0; i < subs.size(); i++){
        //     cout << subs[i] << " ";
        // }
        // cout << endl;
        return maxLength;
    }
};