//dekho simple hai question
// pehle multiplication store kar lo

// fir agar koi zero hai to firse ek naya multiplication
// store karlo 

// fir push_back karte rho
// agar zero aata hai to and countOfZeroes is 1 then add the 
// additionally created multiplication value
// otherwise just add zero

// bas ho gya solve
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>vc;
        int zero=0;
        int mul=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            zero++;
            mul*=nums[i];
        }
        int new_mul=1;
        for(int k=0;k<nums.size();k++)
        {
            if(nums[k]!=0)
            new_mul*=nums[k];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mul!=0)
                vc.push_back(mul/nums[i]);
            else if(mul==0 && nums[i]!=0)
            {
                vc.push_back(mul);
            }
            else if(zero>1)
            {
                vc.push_back(0);
            }
            else if(zero==1)
            {
                if(nums[i]==0)
                {
                    vc.push_back(new_mul);
                }
            }
            
        }
        return vc;
    }
};