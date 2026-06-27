class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        int peri = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 1) {
                    for(int d = 0; d < 4; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        if(nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                            peri++;
                        else if(grid[nr][nc] == 0)
                            peri++;
                    }
                }
            }
        }
        return peri;
    }
};