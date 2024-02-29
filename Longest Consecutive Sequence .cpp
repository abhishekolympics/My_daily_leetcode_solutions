class Solution {
public:
    // int search(vector<int> &nums,int val)
    // {
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(val==nums[i])
    //             return true;
    //     }
    //     return false;
    // }
    int longestConsecutive(vector<int>& nums) {
        //BRUTE FORCE
        //Check for every element
        // if(nums.size()==0) return 0;
        // int longest=1;
        // int n=nums.size();
        // for(int i=0;i<n;i++)
        // {
        //     int x=nums[i];
        //     int count=1;
        //     while(search(nums,x+1)==true)
        //     {
        //         x+=1;
        //         count+=1;
        //     }
        //     longest=max(longest,count);
        // }
        // return longest;

        //optimized approach
        //use a set for storing then check in that set
        if(nums.size()==0) return 0;
        unordered_set<int>s;
        int n=nums.size(),longest=1;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int x=nums[i];
                int count =1;
                while(s.find(x+1)!=s.end())
                {
                    x+=1;
                    count+=1;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};