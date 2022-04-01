/*
Problem: https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1#


Longest Consecutive 1's
Easy

Given a number N. Find the length of the longest consecutive 1s in its binary representation.

Example 1:

Input: N = 14
Output: 3
Explanation: 
Binary representation of 14 is 
1110, in which 111 is the longest 
consecutive set bits of length is 3.

Example 2:

Input: N = 222
Output: 4
Explanation: 
Binary representation of 222 is 
11011110, in which 1111 is the 
longest consecutive set bits of length 4. 

Your Task: 
You don't need to read input or print anything. Your task is to complete the function maxConsecutiveOnes() which returns the length of the longest consecutive 1s in the binary representation of given N.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
*/


#include <bits/stdc++.h>
using namespace std;

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        int count  = 0;
        int maxcnt = 0;
        int n = log2(N) + 1;
        int temp; 
        for(int i = 0; i < n; i++){
            temp = (N >> i) & 1;
            if(temp == 0){
                count = 0;
            }
            else {
                count++;
                if(count > maxcnt)
                    maxcnt = count;
            }
            
        }
        
        return maxcnt;
        
    }
};


int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
} 