class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool Flag[256] = {};

        int MaxLen = 0, CurLen = 0;
        int StartPos = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            int x = s[i];
            if(!Flag[x])
            {
                // none repeat character
                Flag[x] = true;
                ++CurLen;
            }
            else
            {
                // repeat character
                if(MaxLen < CurLen)
                    MaxLen = CurLen;

                // minus substring until substring without current character
                while(Flag[x])
                {
                    int y = s[StartPos];
                    Flag[y] = false;
                    --CurLen;
                    ++StartPos;
                }

                // current character make substring length plus 1
                Flag[x] = true;
                ++CurLen;
            }
        }

        // if the last character is not repeat character
        // Answer should be check again.
        if(MaxLen < CurLen)
            MaxLen = CurLen;

        return MaxLen;
    }
};
