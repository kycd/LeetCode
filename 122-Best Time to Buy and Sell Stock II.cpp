/*
	Greedy, LocalMaximum, End.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;

        int Ans = 0;

        // Ignore heading descreasing sequence.
        int n = 0;
        while(n+1 < prices.size() && prices[n] >= prices[n+1])
            ++n;

        int LocalMin = prices[n],LocalMax = prices[n];
        for(int i = n+1; i < prices.size(); ++i)
        {
            if(LocalMax < prices[i])
                LocalMax = prices[i];
            else if(LocalMax > prices[i])
            {
                Ans += LocalMax - LocalMin;
                LocalMin = LocalMax = prices[i];
            }
        }
        Ans += LocalMax - LocalMin;

        return Ans;
    }
};
