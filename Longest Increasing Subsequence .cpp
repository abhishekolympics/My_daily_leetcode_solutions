class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        //check from end if there is any increasing subsequence
        //then for every element before it add 1 to the value of 
        //the dp to its element after it if it is less than the 
        //element after it
        // and that it
        //at last return the *max_element() of the vector
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]<nums[j] && dp[i]<dp[j]+1)
                {
                    dp[i]=1+dp[j];
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};