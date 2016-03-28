/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return intervals;

        std::sort(intervals.begin(), intervals.end(), cmp);

        vector<Interval> vecAns;
        Interval Cur = intervals[0];

        for(int i = 1; i < intervals.size();++i)
        {
            if(Cur.end >= intervals[i].start)
            {
                Cur.end = std::max(Cur.end, intervals[i].end);
            }
            else
            {
                vecAns.push_back(Cur);
                Cur = intervals[i];
            }
        }
        vecAns.push_back(Cur);
        intervals.erase(intervals.begin(), intervals.end());
        for(int i = 0; i < vecAns.size(); ++i)
            intervals.push_back(vecAns[i]);

        return intervals;
    }

    static bool cmp(Interval x, Interval y)
    {
        if(x.start == y.start)
            return x.end < y.end;
        return x.start < y.start;
    }
};
