class Solution {
public:
    int rob(vector<int> nums, int s, int e)
    {
        if(s > nums.size())
            return 0;

        vector<int> r0(nums.size() + 1), r1(nums.size() + 1);
        r0[s] = 0;
        r1[s] = nums[s-1];

        for(int i = s+1; i <= e; ++i)
        {
            r0[i] = max(r0[i-1], r1[i-1]);
            r1[i] = max(r0[i-1], r1[i-2]) + nums[i-1];
        }

        return max(r0[e], r1[e]);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        return max(nums[0] + rob(nums, 3, nums.size()-1) ,rob(nums, 2, nums.size()));
    }
};
