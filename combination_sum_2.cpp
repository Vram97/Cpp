 class Solution {
public:
    vector<vector<int>> ans;
    int sz;

    void combo(vector<int>cand, vector<int>temp, int sum, int index,int target){
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        else if(sum>target || index>=sz){
            return;
        }
        
        else{
            for(int i=index;i<sz;i++){
                if(i!=index && cand[i]==cand[i-1]){
                    continue;
                }
                temp.push_back(cand[i]);
                combo(cand,temp,sum+cand[i],i+1,target);
                temp.pop_back();
            }
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        sz=candidates.size();

        vector<int> temp;

        combo(candidates,temp,0,0,target);

        return ans;

        
    }
};
