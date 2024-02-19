class Solution {
public:
    int findMin(vector<int>& nums) {
        //BRUTE FORCE

        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     if(nums[i]>nums[i+1])
        //         return nums[i+1];
        // }
        // return nums[0];

        //Optimized O(logn)
        int beg=0,end=nums.size()-1;
        while(beg<end)
        {
            if(nums[beg]<nums[end])
                return nums[beg];

            int mid=(beg+end)/2;
            if(nums[mid]>=nums[beg])
                beg=mid+1;
            else
                end=mid;
        }
        return nums[beg];
    }
};