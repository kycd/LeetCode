class Solution {
public:
    int reverse(int x) {
        // Save Signal status.
        bool Signal = x > 0;
        if(!Signal)
            x = -x;

        // Reverse
        string strRev = "";
        string strIntMax = "2147483647";
        int Ans = 0;
        while(x > 0)
        {
            strRev += '0' + x % 10;
            Ans *= 10;
            Ans += x % 10;
            x /= 10;
        }

        // Check Reverse number is overflow or not.
        if(strRev.length() == strIntMax.length() && strRev > strIntMax)
            return 0;
        else
        {
            // Add Signal
            if(!Signal)
                Ans = -Ans;

            return Ans;
        }
    }
};
