class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        vector<int>dp(s.size()+1,-1);
        return helper(s,s.size()-1,dp);      
    }
    int helper(string s,int curr,vector<int>& dp)
    {
        if(curr<=0)
        {
            return 1;
        }
        if(dp[curr]!=-1)
        {
            return dp[curr];
        }
        int res=0;

        if(s[curr]!='0')
        {
            res=helper(s,curr-1,dp);
        }

        if(s[curr-1]=='1' &&s[curr]>0 || s[curr-1] =='2' && s[curr]>='0' &&s[curr]<='6')
        {
            res+=helper(s,curr-2,dp);
        }
        return dp[curr]=res;
    }
};