class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        // 遍历每一块
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                // 有陆地+1
                if(grid[i][j]=='1'){
                    count++;
                    // 遍历当前陆地连通的岛屿全部置为2
                    search(grid,i,j);
                }
            }
        }
        return count;
    }
    // dfs 遍历
    void search(vector<vector<char>>& grid, int i, int j){
        // 遍历到岛屿块
        if(inArea(i,j,grid.size(),grid[0].size()) && grid[i][j]=='1'){
            // visited 标为2 避免重复计算
            grid[i][j]='2';
            // 访问周边领接位置
            search(grid, i, j+1);
            search(grid, i, j-1);
            search(grid, i+1, j);
            search(grid, i-1, j);
        }
    }
    // 边界判断
    bool inArea(int i, int j, int row, int col){
        return (0<=i)&&(i<row)&&(0<=j)&&(j<col);
    }
};
