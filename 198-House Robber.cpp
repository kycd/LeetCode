class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        vector<int> r0(nums.size() + 1), r1(nums.size() + 1);
        r0[1] = 0;
        r1[1] = nums[0];

        for(int i = 2; i <= nums.size(); ++i)
        {
            r0[i] = max(r0[i-1], r1[i-1]);
            r1[i] = max(r0[i-1], r1[i-2]) + nums[i-1];
        }

        return max(r0[nums.size()], r1[nums.size()]);
    }
};
