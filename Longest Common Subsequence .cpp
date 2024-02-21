class Solution {
public:

    // RECURSION + MEMOIZATION
    // int LCS(string t1,string t2,int n1,int n2,vector<vector<int>>& dp)
    // {
    //     if(n1<0 || n2<0)
    //     {
    //         return 0;
    //     }
    //     if(dp[n1][n2]!=-1)
    //     {
    //         return dp[n1][n2];
    //     }
        
    //     if(t1[n1]==t2[n2])
    //     {
    //         return dp[n1][n2]=(1+LCS(t1,t2,n1-1,n2-1,dp));
    //     }
    //     return dp[n1][n2]=max(LCS(t1,t2,n1-1,n2,dp),LCS(t1,t2,n1,n2-1,dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n1=text1.size(),n2=text2.size();
    //     vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
    //     return LCS(text1,text2,n1-1,n2-1,dp);
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // return LCS(text1,text2,n1,n2);
        int t[n+1][m+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0||j==0)
                {
                    t[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1])
                {
                    t[i][j]=1+ t[i-1][j-1];
                }
                else
                {
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[n][m];
    }
};