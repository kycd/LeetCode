class Solution {
private:
    int f(int n)
    {
        if(n <= 0)
            return 1;
        if(n > 10)
            return 0;

        int Sum = 9, P = 9;
        while(n > 1)
        {
            Sum *= P;
            --P;
            --n;
        }
        return Sum;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        int Ans = 0;
        for(int i = 0; i <= n; ++i)
            Ans += f(i);

        return Ans;
    }
};
