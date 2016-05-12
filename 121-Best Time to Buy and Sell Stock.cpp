/*
	Greedy, End.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;

        int Min = prices[0], Ans = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(Min > prices[i])
                Min = prices[i];
            if(Ans < prices[i] - Min)
                Ans = prices[i] - Min;
        }

        return Ans;
    }
};
