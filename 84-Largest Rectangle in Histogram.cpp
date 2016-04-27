class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> Left(heights.size(), 0);
        vector<int> Right(heights.size(), heights.size()-1);

        stack<int> sr;
        for(int i = 0; i < heights.size(); ++i)
        {
            while(!sr.empty() && heights[sr.top()] > heights[i])
            {
                Right[sr.top()] = i-1;
                sr.pop();
            }

            sr.push(i);
        }

        stack<int> sl;
        for(int i = heights.size() - 1; i >= 0; --i)
        {
            while(!sl.empty() && heights[sl.top()] > heights[i])
            {
                Left[sl.top()] = i+1;
                sl.pop();
            }

            sl.push(i);
        }

        int Ans = 0;
        for(int i = 0; i < heights.size(); ++i)
        {
            int Area = (Right[i] - Left[i] + 1) * heights[i];

            if(Area > Ans)
                Ans = Area;
        }

        return Ans;
    }
};
