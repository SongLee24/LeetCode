class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length();
        int lp = p.length();
        vector<vector<bool>> dp(ls+1, vector<bool>(lp+1, false));

        dp[0][0] = true;   // 初始化
        for(int i = 1; i < lp && p[i] == '*'; i+=2){
            dp[0][i+1] = true;
        }

        for(int i = 1; i <= ls; ++i){
            for(int j = 1; j <= lp; ++j){
                if(p[j-1] == '.' || p[j-1] == s[i-1])
                    dp[i][j] = dp[i-1][j-1];
                else if(j > 1 && p[j-1] == '*')
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (p[j-2] == '.' || s[i-1] == p[j-2]));   // .*
            }
        }
        return dp[ls][lp];
    }
};