/*
Problem: https://leetcode.com/problems/permutation-in-string/

567. Permutation in String
Medium

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:  

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:

    1 <= s1.length, s2.length <= 104
    s1 and s2 consist of lowercase English letters.
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int s = 0, e = 0, i, j;
        bool flag = true;
        
        if(m < n)           //s2 shorter than s1 (No permutation of s1 can be present in s2)
            return false;
        
        vector<int> s1freq(26, 0);              //Stores freq of each alphabet present in s1
        vector<int> s2freq(26, 0);              //Stores freq of each alphabet present in s1
        
        for(i = 0; i < n; i++){                 //traverse s1 and calculate frequencies
            s1freq[s1[i] - 'a']++;
        }
        
        while(e < m){
            while((e < m) && (e-s < n)){        //from window size 1 to n
                if(s1freq[s2[e] - 'a'] == 0){               //if the new element is not persent in s1 then discard all frequencies and shift the window to end index + 1 with window size as 1
                    fill(s2freq.begin(), s2freq.end(), 0); //making all freq of s2 as 0
                    s = e+1;            
                    e = e+1;
                }
                else{                           //new element is present in s1
                    s2freq[s2[e] - 'a']++;      //increase its freq in s2
                    e++;                        //increase window size by 1
                }  
            }
            
            flag = true;
            for(i = 0; i < 26; i++){
                if(s1freq[i] != s2freq[i]){         //true if any freq between s1 an s2 is different which implies the substring is not a permutation of s1
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                return true;                //substring is a permutation of s1
            else{
                if(e >= m)                  //end reached
                    break;
                s2freq[s2[s] - 'a']--;      //s2 end not reached but move start index to s+1
                s++;
            }
        }
        return false;                       //there is no permutation of s1 present in s2
    }
};