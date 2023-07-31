class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        const int m=grid[0].size();
        const int n=grid.size();
        int sum=0;

        for(int i=0;i<m;i++){
            sum+=grid[0][i];
            grid[0][i]=sum;
            // cout<<"FIrst"<<endl;
        }

        sum=0;

        for(int i=0;i<n;i++){
            sum+=grid[i][0];
            grid[i][0]=sum;
            // cout<<"Second"<<endl;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[j][i]+=min(grid[j-1][i],grid[j][i-1]);
                // cout<<grid[i][j]<<endl;
            }
        }

        return grid[n-1][m-1];

    }
};
