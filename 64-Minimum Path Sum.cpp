class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> Map(grid);

        for(int i = 1; i < Map.size(); ++i)
            Map[i][0] += Map[i-1][0];
        for(int i = 1; i < Map[0].size(); ++i)
            Map[0][i] += Map[0][i-1];
        for(int i = 1; i < Map.size(); ++i)
            for(int j = 1; j < Map[i].size(); ++j)
                Map[i][j] += min(Map[i-1][j], Map[i][j-1]);

        return Map[Map.size()-1][Map[0].size()-1];
    }
};
