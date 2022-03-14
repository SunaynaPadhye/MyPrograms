/*
Problem: https://leetcode.com/problems/valid-parentheses/

20. Valid Parentheses
Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
        int i;
        
        for(i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                stc.push(s[i]);
            else if(s[i] == ')'){
                if(!stc.empty() && stc.top() == '(')
                    stc.pop();
                else return false;
            }
            else if(!stc.empty() && s[i] == '}'){
                if(stc.top() == '{')
                    stc.pop();
                else return false;
            }
            else if(!stc.empty() && s[i] == ']'){
                if(stc.top() == '[')
                    stc.pop();
                else return false;
            }
            else return false;
            
        }
        
        return stc.empty();
            
    }
};