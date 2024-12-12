class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int sz=matrix.size();
        vector<vector<int>> v(sz,vector<int>(sz,1001));
        int x;

        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                x=sz-1-i;
                v[j][x]=matrix[j][x];
                if(v[i][j]==1001){
                    matrix[j][x]=matrix[i][j];
                }
                else{
                    matrix[j][x]=v[i][j];
                }

            }
        }
        
    }
};
