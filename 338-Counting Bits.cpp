class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> Ans(num+1, 0);

        int t = 1;
        for(int n = 1; n <= num; ++n)
        {
            if(n >= t*2)
                t *= 2;
            Ans[n] = Ans[n-t] + 1;
        }

        return Ans;
    }
};
