class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());

        int i = 0, j = tmp.size()-1;
        bool Flag = false;

        while(!Flag && i < j)
        {
            while(tmp[j] > target - tmp[i])
                --j;

            if((target == tmp[i] + tmp[j]) && i != j)
            {
                Flag= true;
            }
            else
                ++i;
        }

        vector<int> Ans;
        for(int k = 0; k < nums.size(); ++k)
        {
            if(nums[k] == tmp[i] || nums[k] == tmp[j])
                Ans.push_back(k);
        }

        return Ans;
    }
};
