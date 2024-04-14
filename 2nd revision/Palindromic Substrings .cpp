class Solution {
public:

    BRUTE FORCE 
    TC=O(n^3)
    SC=O(1)
    bool checkForPalindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size(),count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(checkForPalindrome(s,i,j))
                {
                    count++;
                }
            }
        }
        return count;
    }

    RECURSION + MEMOIZATION
    TC=O(n^2) SC=O(n^2)
    int mem[1001][1001];
    Solution()
    {
        memset(mem,-1,sizeof(mem));
    }
    int check(string s, int i, int j)
    {
        if(i>j) return true;
        if(mem[i][j]!=-1)
        {
            return mem[i][j];
        }
        if(s[i]==s[j])
        {
            return mem[i][j]=check(s,i+1,j-1);
        }
        return mem[i][j]=false;
    }

    int countSubstrings(string s) {
        int n=s.size(),count=0;
        // memset(mem,-1,sizeof(mem));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(check(s,i,j))
                {
                    count++;
                }
            }
        }
        return count;
    }
    
    DYNAMIC PROGRAMMING
    TC=O(n^2) SC=O(n^2)


    int countSubstrings(string s) {
        int n=s.size(),count=0;
        vector<vector<bool>>dp(n,vector(n,false));
        for(int L=1;L<=n;L++)
        {
            for(int i=0;i<=n-L;i++)
            {
                int j=i+L-1;
                if(i==j) dp[i][j]=true;

                else if(i+1==j)
                {
                    dp[i][j]=(s[i]==s[j]);
                }
                else if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }

    //BEST APPROACH
    // TC=O(n^2) SC=O(1)
    int count;
    void check(string s,int i,int j,int n)
    {
        while(i>=0 && j<n && s[i]==s[j])
        {
            i--;
            j++;
            count++;
        }
    }
    int countSubstrings(string s) {
        count=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            check(s,i,i,n);
            check(s,i,i+1,n);
        }
        return count;
    }
};