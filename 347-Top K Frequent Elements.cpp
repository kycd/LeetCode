class Node{
public:
    int x, y;
    Node(int _x, int _y): x(_x), y(_y)
    {
    }
};
bool fncomp (Node lhs, Node rhs)
{
    if(lhs.x == rhs.x)
        return lhs.y > rhs.y;
    else
        return lhs.x < rhs.x;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> Cnt;
        for(int i = 0; i < nums.size(); ++i)
            Cnt[nums[i]]++;

        vector<Node> ReCnt;
        map<int,int>::iterator it;
        for (it=Cnt.begin(); it!=Cnt.end(); ++it)
        {
            Node r(it->second, it->first);
            ReCnt.push_back(r);
        }

        // for(int i = 0; i < ReCnt.size(); ++i)
        //     cout << ReCnt[i].x << " " << ReCnt[i].y << endl;
        sort(ReCnt.begin(), ReCnt.end(), fncomp);
        // for(int i = 0; i < ReCnt.size(); ++i)
        //     cout << ReCnt[i].x << " " << ReCnt[i].y << endl;

        vector<int> Ans;
        for(int i = ReCnt.size()-1; k > 0; --i, --k)
            Ans.push_back(ReCnt[i].y);

        return Ans;
    }
};
