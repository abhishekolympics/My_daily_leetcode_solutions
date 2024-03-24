// Watch this video https://www.youtube.com/watch?v=tGAMyZxlwuA


class Solution {
public:

    //brute force, check for all substring, if that is a palindrome or not
    //time complexity= O(n^3)
    // bool check(string &s, int i, int j)
    // {
    //     if(i>j)
    //     {
    //         return true;
    //     }
    //     if(s[i]==s[j])
    //     {
    //         return check(s,i+1,j-1);
    //     }
    //     return false;
    // }
    // int countSubstrings(string s) {
    //     int n=s.size(),res=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i;j<n;j++)
    //         {
    //             if(check(s,i,j))
    //             {
    //                 res++;
    //             }
    //         }
    //     }
    //     return res;
    // }

    //memoization, check for that substring, if it is already checked for palindrome or not
    //time complexity= O(n^2)
    // int t[1001][1001];
    // bool check(string &s, int i, int j)
    // {
    //     if(i>j)
    //     {
    //         return true;
    //     }
    //     if(t[i][j]!=-1)
    //     {
    //         return t[i][j];
    //     }
    //     if(s[i]==s[j])
    //     {
    //         return t[i][j]=check(s,i+1,j-1);
    //     }
    //     return t[i][j]=false;
    // }
    // int countSubstrings(string s) {
    //     memset(t,-1,sizeof(t));
    //     int n=s.size(),res=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i;j<n;j++)
    //         {
    //             if(check(s,i,j))
    //             {
    //                 res++;
    //             }
    //         }
    //     }
    //     return res;

    //Dynamic Programming, 
    //Time Complexity=O(n^2)
    //Space Complexity = O(n^2)
    // int countSubstrings(string s) {
    //     int n=s.size(),count=0;
    //     vector<vector<bool>>t(n+1,vector<bool>(n+1,false));
    //     for(int L=1;L<=n;L++)
    //     {
    //         for(int i=0;i+L-1<n;i++)
    //         {
    //             int j=i+L-1;
    //             if(i==j) t[i][j]=true;
    //             else if(i+1==j)
    //             {
    //                 t[i][j]=(s[i]==s[j]);
    //             }
    //             else
    //             {
    //                 t[i][j]=(s[i]==s[j] && t[i+1][j-1]);
    //             }
    //             if(t[i][j]) count++;
    //         }
    //     }
    //     return count;
    // }

    //Best Approach
    //Time Complexity = O(n^2)
    //Space Complexity = O(1)
    int count;
    void check(string s, int i, int j, int n)
    {
        while(i>=0 && j<n && s[i]==s[j])
        {
            count++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int n=s.size();
        count=0;
        for(int i=0;i<n;i++)
        {
            check(s,i,i,n);         //check for odd length substrings
            check(s,i,i+1,n);       //check for even length substrings
        }
        return count;
    }
};