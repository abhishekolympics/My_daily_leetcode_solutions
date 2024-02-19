class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN,pref=1,n=nums.size(),suff=1;
        for(int i=0;i<n;i++)
        {
            if(suff==0) suff=1;
            if(pref==0) pref=1;

            suff*=nums[i];
            pref*=nums[n-i-1];
            maxi=max(maxi,max(suff,pref));
        }
        return maxi;
    }
};
