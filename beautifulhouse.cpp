#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] == 1 || grid[i][j] == 0)
    {
        return;
    }
    visited[i][j] = true;

    solve(grid, i + 1, j, visited);
    solve(grid, i - 1, j, visited);
    solve(grid, i, j + 1, visited);
    solve(grid, i, j - 1, visited);
}
int numIslands(vector<vector<int>> &grid)
{

    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 and visited[i][j] == false)
            {
                solve(grid, i, j, visited);
                if( (i+1<n and j+1<m and grid[i+1][j+1]==1 and grid[i+1][j]==0 and grid[i][j+1]==0 )){
                    continue;
                }
                if( (i-1>=0 and j-1>=0 and grid[i-1][j-1]==1 and grid[i-1][j]==0 and grid[i][j-1]==0 )){
                    continue;
                }
                if( (i+1<n and j-1>=0 and grid[i+1][j-1]==1 and grid[i+1][j]==0 and grid[i][j-1]==0 )){
                    continue;
                }
                if( (i-1>=0 and j+1<m and grid[i-1][j+1]==1 and grid[i-1][j]==0 and grid[i][j+1]==0 )){
                    continue;
                }
                

                

                count++;
            }
        }
    }

    return count;
}

int main(){

    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<numIslands(grid)<<endl;

    return 0;
}