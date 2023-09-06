class Solution {
public:
    void combo(string str,int numLeft,int numRight,vector<string> &ans){
        if(numLeft==0 && numRight==0){
            ans.emplace_back(str);
            return ;
        }

        // if(numLeft+numRight==n){
        //     ans.emplace_back(str);
        //     return;
        // }

        for(int i=0;i<2;i++){
            if(i==0){
                if(numLeft>numRight){
                    combo(str+")",numLeft,numRight-1,ans);
                    // str.pop_back();
                }
            }
            else{
                combo(str+"(",numLeft-1,numRight,ans);
            }
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        combo("",n,n,ans);
        return ans;
    }
};
