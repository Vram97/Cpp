class Solution {

public:

    void combo(const vector<int> &nums,vector<int> temp,short unsigned int ind,const int &sz,vector<vector<int>> &ans, set<vector<int>>&st){

        if(ind>sz){
            return;
        }
        if(st.find(temp)==st.end()){
            ans.emplace_back(temp);
            st.insert(temp);
        }

        for(int i=ind;i<sz;i++){
            temp.emplace_back(nums[i]);
            combo(nums,temp,i+1,sz,ans,st);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
        // vector<int>::iterator it= unique(nums.begin(),nums.end());

        // const int sz=distance(nums.begin(),it);

        // nums.resize(sz);


        const int sz=nums.size();

        vector<vector<int>> ans;

        vector<int> temp;

        set<vector<int>> st;

        combo(nums,temp,0,sz,ans,st);

        return ans;


    }
};
