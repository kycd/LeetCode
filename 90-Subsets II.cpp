class Solution {
public:
    void BackTrace(vector<vector<int>>& Ans, vector<int> nums, vector<int>& vec, int pos)
    {
        Ans.push_back(vec);
        for(int i = pos+1; i < nums.size(); ++i)
        {
            if(i == pos+1 || nums[i] != nums[i-1])
            {
                vec.push_back(nums[i]);
                BackTrace(Ans, nums, vec, i);
                vec.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> Ans;

        sort(nums.begin(), nums.end());
        vector<int> vec;
        BackTrace(Ans, nums, vec, -1);

        return Ans;
    }
};
