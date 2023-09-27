class Solution {
public:
    void combo(const vector<int> &cand,int ind,int tar,vector<int> temp,vector<vector<int>>&ans,const int &sz){

        if(tar==0){
            // sort(temp.begin(),temp.end());
            // if(mp.find(temp)==mp.end()){
            // mp.insert(temp);
            ans.emplace_back(temp);
            
            return;
        }

        if(tar<0){
            return;
        }

        for(int i=ind;i<sz;i++){

            temp.emplace_back(cand[i]);
            combo(cand,i,tar-cand[i],temp,ans,sz);
            temp.pop_back();
            
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        const int sz=candidates.size();

        // set<vector<int>> m;

        vector<vector<int>> ans;
        vector<int> t;

        combo(candidates,0,target,t,ans,sz);

        return ans;
        
    }
};
