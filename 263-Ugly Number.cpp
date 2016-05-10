class Solution {
public:
    bool isUgly(int num) {
        num = Remove(num, 2);
        num = Remove(num, 3);
        num = Remove(num, 5);

        return (num == 1);
    }

    int Remove(int num, int p)
    {
        while(num > 0 && num % p == 0)
            num /= p;
        return num;
    }
};
