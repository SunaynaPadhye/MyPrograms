/*
Problem: https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1#


Rightmost different bit
Easy 

Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers.

Example 1: 

Input: M = 11, N = 9
Output: 2
Explanation: Binary representation of the given 
numbers are: 1011 and 1001, 
2nd bit from right is different.

Example 2:

Input: M = 52, N = 4
Output: 5
Explanation: Binary representation of the given 
numbers are: 110100 and 0100, 
5th-bit from right is different.

User Task:
The task is to complete the function posOfRightMostDiffBit() which takes two arguments m and n and returns the position of first different bits in m and n. If both m and n are the same then return -1 in this case.

Expected Time Complexity: O(max(log m, log n)).
Expected Auxiliary Space: O(1).

Constraints:
0 <= M <= 109
0 <= N <= 109

*/


#include <bits/stdc++.h>
using namespace std;
 

//APPROACH 1:
class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        int rem1, rem2, count = 0;
        while(m!=0 || n!=0){
            if(m == 0)
                rem1 = 0;
            else{
                rem1 = m%2;
                m = m/2;
            }
            
            if(n == 0)
                rem2 = 0;
            else{
                rem2 = n%2;
                n = n/2;
            }
            count++;
            if(rem1 != rem2)
                return count;
            
        }
        return -1;
        // Your code here
    }
};

//APPROACH 2:
class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        int x = m ^ n;

        if(x == 0)
            return -1;
        
        return log2(x & -x) + 1;
        // Your code here
    }
};

int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
}   