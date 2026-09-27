class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int column = 0; column < grid[row].size(); ++column) {
                if (grid[row][column] == '1') {
                    doBFS(row, column, grid);
                    ++numIslands;
                }
            }
        }
        return numIslands;
    }

    void doBFS(int rowIn, int columnIn, vector<vector<char>>& grid) {
        std::queue<std::pair<int, int>> q {{{rowIn, columnIn}}};
        while (!q.empty()) {
            std::pair<int, int> loc = q.front();
            int row = loc.first;
            int column = loc.second;
            q.pop();

            std::vector<std::pair<int, int>> toCheck {
                {row + 1, column},
                {row - 1, column},
                {row, column + 1},
                {row, column - 1}
            };

            for (std::pair<int, int> location : toCheck) {
                int nrow = location.first;
                int ncolumn = location.second;
                if (nrow >= 0 && ncolumn >= 0 && nrow < grid.size() && ncolumn < grid[row].size()
                    && grid[nrow][ncolumn] == '1') {
                    q.push({nrow, ncolumn});
                    grid[nrow][ncolumn] = 0;
                }
            }
        }
    }
};
