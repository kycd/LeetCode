class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> Map(grid);

        int Ans = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    BFS(grid, i, j);
                    ++Ans;
                }
            }
        }

        return Ans;
    }

    void BFS(vector<vector<char>>& grid, int x, int y)
    {
        queue<pair<int, int>> q;

        grid[x][y] = '0';
        q.push(pair<int, int>(x, y));

        pair<int, int> Head;
        while(!q.empty())
        {
            Head = q.front();
            q.pop();

            TryPushQueue(q, grid, Head.first-1, Head.second);
            TryPushQueue(q, grid, Head.first+1, Head.second);
            TryPushQueue(q, grid, Head.first, Head.second-1);
            TryPushQueue(q, grid, Head.first, Head.second+1);
        }
    }

    void TryPushQueue(queue<pair<int, int>> &q, vector<vector<char>>& grid, int x, int y)
    {
        if(x >= 0 && x < grid.size() && y >=0 && y < grid[0].size())
        {
            if(grid[x][y] == '1')
            {
                grid[x][y] = '0';
                q.push(pair<int, int>(x, y));
            }
        }
    }
};
