class Solution {
public:
    bool subsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>>mem(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    mem[i][j]=false;
                }
                if(j==0)
                {
                    mem[i][j]=true;
                }
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]>j)
                {
                    mem[i][j]=mem[i-1][j];
                }
                else if(arr[i-1]<=j)
                {
                    mem[i][j]=mem[i-1][j-arr[i-1]]||mem[i-1][j];
                }
            }
        }
        return mem[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        sum/=2;
        return subsetSum(nums,sum);
    }
};