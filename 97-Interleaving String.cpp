class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;

        vector<vector<bool>> dp;
        dp.resize(s1.length() + 1);
        for(int i = 0; i <= s1.length(); ++i)
            dp[i].resize(s2.length() + 1, false);

        dp[0][0] = true;

        for(int i = 0; i <= s1.length(); ++i)
        {
            for(int j = 0; j <= s2.length(); ++j)
            {
                if(i > 0 && s1[i-1] == s3[i+j-1] && dp[i-1][j])
                    dp[i][j] = true;
                else if(j > 0 && s2[j-1] == s3[i+j-1] && dp[i][j-1])
                    dp[i][j] = true;
            }
        }

        return dp[s1.length()][s2.length()];
    }
};
