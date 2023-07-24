class Solution {
public:
    bool combo(int start,int &k,int n,vector<int>& v,vector<int> temp,vector<vector<int>> &ans){
        int sz=temp.size();
        if(sz>k || n<0){
            return false;
        }
        if(n==0 && sz==k){
            ans.emplace_back(temp);
            return false;
        }

        for(int i=start;i<9;i++){
            temp.emplace_back(v[i]);
            bool cont=combo(i+1,k,n-v[i],v,temp,ans);

            if(cont==false){
                break;
            }
            temp.pop_back();
        }

        return true;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums{1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;

        auto x=combo(0,k,n,nums,temp,ans);
        
        return ans;
    }
};
