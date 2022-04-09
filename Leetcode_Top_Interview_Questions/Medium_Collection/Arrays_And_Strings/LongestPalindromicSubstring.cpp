class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int maxlen = 1, start = 0;
        int i, j, k;
        
        for(i = 0; i < n; i++){
            dp[i][i] = true;
        }
        
        for(i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                maxlen = 2;
                start = i;
            }
        }
        
        for(k = 3; k <= n; k++){
            for(i = 0; i < n-k+1; i++){
                j = i+k-1;
                
                if(dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = true;
                    
                    if(k > maxlen){
                        maxlen = k;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxlen);
    }
};