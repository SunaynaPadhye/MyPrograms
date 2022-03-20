/*
Problem: https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/778/

Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

Constraints:

    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string temp;
        vector<vector<string>> res;
        unordered_map<string, int> um;
        for (auto str: strs)
        {
            temp = str;
            sort(temp.begin(), temp.end());
            if (um[temp]>0)                      
            {
                res[um[temp] - 1].push_back(str);
            }
            else
            {
                res.push_back({str});
                um[temp] = res.size();           
            }
            
        }
                
        return res;
    }
};