class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return helper(nums,0,dp);
    }
    bool helper(vector<int>& nums, int curr,vector<int>& dp)
    {
        if(curr ==nums.size()-1) return true;
        if(nums[curr]==0) return false;
        if(dp[curr]!=-1) return dp[curr];
        int reach=curr+nums[curr];
        for(int i=curr+1;i<=reach;i++)
        {
            if(i<nums.size() && helper(nums,i,dp))
                return dp[curr]=true;
        }
        return dp[curr]=false;
    }
};