class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        vector<set<char>> rows(9,s);
        vector<set<char>> cols(9,s);

        vector<vector<set<char>>> box(3,vector<set<char>>(3,s));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]=='.'){
                    continue;
                }
                if(rows[i].contains(board[i][j]) || cols[j].contains(board[i][j]) || box[i/3][j/3].contains(board[i][j])){
                    return false;
                }

                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                box[i/3][j/3].insert(board[i][j]);



                // // If any of this fails return false
                // if(!r1.second || !r2.second || !r3.second){
                //     return false;
                // }
            }
        }
        return true;
    }
};
