class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long Sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            Sum += nums[i];
        }

        int Ans = (long long)nums.size() * (nums.size()+1) / 2 - Sum;

        return Ans;
    }
};
