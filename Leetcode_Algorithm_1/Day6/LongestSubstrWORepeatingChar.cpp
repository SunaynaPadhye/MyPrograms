/*
Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/

3. Longest Substring Without Repeating Characters
Medium

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
        int st = 0, e = 0;                  //st: start index of window, e: end index of window
        
        vector<string> subs;                //a vector to store all required longest substrings
        vector<bool> al(256, false);        
        
        while(e < s.length()){
            if(al[s[e]]){                       //new element present in subtsring
                al[s[st]] = false;              
                st++;
            }
            else{                              //new element not present in substring
                al[s[e]] = true;
                curLength = e-st+1;           //current window length
                
                if(curLength == maxLength)
                    subs.push_back(s.substr(st, curLength));            
                if(curLength > maxLength){                              //found longer substring 
                    maxLength = curLength;
                    subs.clear();                                       //hence remove all previously stored shorter subsstrings
                    subs.push_back(s.substr(st, curLength));            //and store newly found substring (or use maxLength instead of curLength)
                }
                e++;
            }
        }

        /*
        for(int i = 0; i < subs.size(); i++){                //if substrings are asked to be printed, use this.
            cout << subs[i] << " ";
        }
        cout << endl;
        */
       
        return maxLength;
    }
};

/*
This solution uses Sliding Window technique.
*/