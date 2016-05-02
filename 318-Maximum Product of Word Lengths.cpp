class Solution {
private:
    int arr[31];
    void CreateBitmask()
    {
        arr[0] = 1;
        for(int i = 1; i < 26; ++i)
            arr[i] = arr[i-1] * 2;
    }
public:
    int maxProduct(vector<string>& words) {
        CreateBitmask();

        int Ans = 0;

        vector<int> vec;
        for(int i = 0; i < words.size(); ++i)
        {
            int x = 0;
            for(int j = 0; j < words[i].length(); ++j)
            {
                int alpha = words[i][j] - 'a';
                x |= arr[alpha];
            }
            vec.push_back(x);
        }

        for(int i = 0; i < vec.size(); ++i)
        {
            for(int j = i + 1; j < vec.size(); ++j)
            {
                if((vec[i] & vec[j]) == 0)
                {
                    int Union = words[i].length() * words[j].length();
                    if(Union > Ans)
                        Ans = Union;
                }
            }
        }

        return Ans;
    }
};
