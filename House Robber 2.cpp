class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1=0,n=nums.size(),rob2=0;
        if(n==1) return nums[0];
        for(int i=0;i<=n-2;i++)
        {
            int temp=max(rob1+nums[i],rob2);
            rob1=rob2;
            rob2=temp;
        }
        int rob11=0,rob22=0;
        for(int i=1;i<=n-1;i++)
        {
            int temp=max(rob11+nums[i],rob22);
            rob11=rob22;
            rob22=temp;
        }
        return max(rob2,rob22);
    }
};