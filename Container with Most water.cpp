class Solution {
public:
    int maxArea(vector<int>& height) {
        //brute force 
        // we can calculate all the areas
        // return the max area
        // int maxi=INT_MIN;
        // int n=height.size();
        // for(int i=0;i<n-1;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(height[j]>=height[i] && height[i]*(j-i)>maxi)
        //         {
        //             maxi=height[i]*(j-i);
        //         }
        //         else if(height[i]>height[j] && height[j]*(j-i)>maxi)
        //         {
        //             maxi=height[j]*(j-i);
        //         }
        //     }
        // }
        // return maxi;

        //Optimized Solution
        //we need to find the maximum area from each end
        // we can start with two ends and then move the which is bigger
        // beg=9 and end=8 then move end
        // beg=9 and end=10 then move beg
        int maxi=INT_MIN;
        int n=height.size();
        int beg=0,end=n-1;
        while(beg<end)
        {
            if(maxi<min(height[beg],height[end])*(end-beg))
            {
                maxi=min(height[beg],height[end])*(end-beg);
            }
            if(height[beg]>height[end])
            {
                end--;
            }
            else
            {
                beg++;
            }
        }
        return maxi;
    }
};