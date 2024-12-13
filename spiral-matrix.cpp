class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        unordered_map<int,pair<int,int>> dir{{0,{0,1}}, {1,{1,0}}, {2,{0,-1}}, {3,{-1,0}}};

        const int rows=matrix.size();
        const int cols=matrix[0].size();
        // vecor<vector<int>>v(rows,vector<int>(cols,-101));
        vector<int> ans;

        int state=0;
        int i=0;
        int j=0;
        // v[i][j]=matrix[i][j];
        ans.emplace_back(matrix[i][j]);
        matrix[i][j]=-101;
        int count=0;

        while(true){
            
            int temp_i=dir[state].first+i;
            int temp_j=dir[state].second+j;

            if((temp_i>=0 && temp_i<rows) && (temp_j>=0 && temp_j<cols)){
                if(matrix[temp_i][temp_j]!=-101){
                    i=temp_i;
                    j=temp_j;
                    ans.emplace_back(matrix[i][j]);
                    matrix[i][j]=-101;
                    count=0;
                }
                else{
                    count++;
                    if(state!=3){
                        state++;
                    }
                    else{
                        state=0;
                    }
                }
                // v[temp_i][temp_j]=matrix[temp_i][temp_j];
                // matrix[temp_i][temp_j]=matrix[i][j];
            }
            else{
                count++;
                if(state!=3){
                    state++;
                }
                else{
                    state=0;
                }
            }
            if(count==2){
                break;
            }
        }

        return ans;
        
    }
};
