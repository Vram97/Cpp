class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> indices;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                for(int x:v){
                    for(int y:v){
                        int nei_x=i+x;
                        int nei_y=j+y;
                        if(nei_x>=m || nei_x<0 || nei_y>=n || nei_y<0){
                            ;
                        }
                        else{
                            if(x==0 && y==0){
                                int curr=board[nei_x][nei_y];
                            }
                            else{
                                if(board[nei_x][nei_y]==1 || board[nei_x][nei_y]==-1){
                                    count++;
                                }
                            }
                        }
                    }
                }
                int curr=board[i][j];
                if(curr==1 || curr==2){
                    if(count<2){
                        vector<int> v{i,j};
                        // cout<<v[0]<<endl;

                        board[i][j]=-1;
                        indices.push_back(v);
                    }
                    if(count>3){
                        vector<int> v{i,j};
                        // cout<<v[0]<<endl;

                        board[i][j]=-1;
                        indices.push_back(v);

                    }
                }
                else{
                    if(count==3){
                        vector<int> v{i,j};
                        // cout<<v[0]<<endl;
                        board[i][j]=2;
                        indices.push_back(v);

                    }

                }
            }
        }

        for(vector<int> nn:indices){
            cout<<nn[0]<<endl;
            if(board[nn[0]][nn[1]]==-1){
                board[nn[0]][nn[1]]=0;
            }
            if(board[nn[0]][nn[1]]==2){
                board[nn[0]][nn[1]]=1;
            }
        }

        


    }
private:
    vector<int> v{-1,0,1};
};
