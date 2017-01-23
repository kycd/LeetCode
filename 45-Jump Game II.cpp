class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> JumpTimes(nums.size());
        int MaxPos = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = MaxPos + 1; j <= i + nums[i] && j < nums.size(); ++j)
                JumpTimes[j] = JumpTimes[i] + 1;
            MaxPos = max(MaxPos, i + nums[i]);
        }

        return JumpTimes[nums.size()-1];
    }
};
