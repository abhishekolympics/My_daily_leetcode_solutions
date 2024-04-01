// class Solution {
// public:
//     //BRUTE FORCE
//     //SIMPLE RECURSION
//     //TC=O(2^n) SC=O(n)
//     int helper(vector<int>& nums,int prev, int current)
//     {
//         if(current<0) return 0;
//         int included=0;
//         if(nums[current]<prev)
//             included=1+helper(nums,nums[current],current-1);
//         int excluded=helper(nums,prev,current-1);
//         return max(included,excluded);
//     }
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n=nums.size(),prev=INT_MAX;
//         return helper(nums,prev,n-1);
//     }
// };

    //MEMOIZATION
    //TC=O(n^2) SC=O(n^2)
class Solution {
public:
    int helper(vector<int>& nums,int prev, int current, vector<vector<int>>& dp)
    {
        if(current<0) return 0;
        if(dp[current][prev+1]!=-1)
            return dp[current][prev+1];
        int included=0;
        if(prev==-1 || nums[current]<nums[prev])
            included=1+helper(nums,current,current-1,dp);
        int excluded=helper(nums,prev,current-1,dp);
        return dp[current][prev+1]=max(included,excluded);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size(),prev=-1;
        vector<vector<int>>rec(n+1,vector<int>(n+1,-1));
        return helper(nums,prev,n-1,rec);
    }
};
