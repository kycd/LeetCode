class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();

        int len = 1;  // i: the current length of non-duplicate array.
        int sp = 1;  // j: search pointer.
        int val = nums[0]; // val: current non-duplicate maximum value.

        while(sp < nums.size())
        {
            // Find next non-duplicate
            while(sp < nums.size() && nums[sp] <= val)
                ++sp;

            // if j is valid index => finded!
            if(sp < nums.size())
            {
                swap(nums[len], nums[sp]);
                val = nums[len];
                ++len;
                ++sp;
            }
        }
        return len;
    }
};
