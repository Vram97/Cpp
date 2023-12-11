class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;
        // set<vector<int>> s;

        sort(nums.begin(),nums.end());

        ans.emplace_back(nums);

        while(next_permutation(nums.begin(),nums.end())){
            // if(s.find(nums)==s.end()){
            ans.emplace_back(nums);
                // s.insert(nums);
            // }
        }

        return ans;
        
    }
