class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //BRUTE FORCE
        //O(n^3 * log(unique triplets))
        // set<vector<int>>res;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         for(int k=j+1;k<nums.size();k++)
        //         {
        //             if(nums[i]+nums[j]+nums[k]==0)
        //             {
        //                 vector<int>inte;
        //                 inte.push_back(nums[i]);
        //                 inte.push_back(nums[j]);
        //                 inte.push_back(nums[k]);
        //                 sort(inte.begin(),inte.end());
        //                 res.insert(inte);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>res1(res.begin(),res.end());
        // return res1;

        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            
            int j=i+1;
            int k=n-1;

            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)
                    j++;
                else if(sum>0)
                    k--;
                else if(sum==0)
                {
                    vector<int>mid={nums[i],nums[j],nums[k]};
                    res.push_back(mid);

                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};