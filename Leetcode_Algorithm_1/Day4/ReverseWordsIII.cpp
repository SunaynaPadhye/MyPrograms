/*
Problem: https://leetcode.com/problems/reverse-words-in-a-string-iii/

557. Reverse Words in a String III
Easy

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "God Ding"
Output: "doG gniD"

Constraints:

    1 <= s.length <= 5 * 104
    s contains printable ASCII characters.
    s does not contain any leading or trailing spaces.
    There is at least one word in s.
    All the words in s are separated by a single space.

*/

class Solution {
public:
    void rev(string &s, int i, int j){              //Reverses characters from index i to j in string s
        char temp;
        while(i < j){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            
            i++; j--;
        }
    }

    string reverseWords(string s) {
        int n = s.length();
        int white;
        int i = 0, j;                                  //i stores index of first letter of word; j stores index of last letter of word
        
        for(white = 0; white < n; white++){             
            if(s[white] == ' '){                        //true when whitespace occurs at index white
                j = white - 1;                          //last letter of word at white - 1
                rev(s, i, j);                           //reverse the letters of word from i to j
                i = white + 1;                          //first letter of next word set to white + 1
            }
        }
        
        j = n - 1;                                      //reversing the remaining last word of string s
        rev(s, i, j);
        
        return s;
        
    }
};