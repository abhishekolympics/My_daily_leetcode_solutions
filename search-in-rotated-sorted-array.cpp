class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int beg=0,end=n-1;
        int pivot=nums[0];
        while(beg<=end)
        {
            int mid=(beg+end)/2;
            if(nums[mid]>nums[n-1])
            {
                beg=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }

        int res=binarySearch(nums,0,beg-1,target);

        if(res!=-1) 
            return res;
        else
            return binarySearch(nums,beg,n-1,target);
    }
    int binarySearch(vector<int>& nums,int left,int right,int target)
    {
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return -1;
    }
};