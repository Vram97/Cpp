class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        map<vector<int>,int> seen;
        // int sz=ans.size();
        ans.push_back(nums);
        seen[nums]=1;

        int sz=ans.size();

        int counter=0;
        while(true){
            for(int j=0;j<ans[counter].size();j++){
                temp=ans[counter];
                temp.erase(temp.begin()+j);

                if(seen.count(temp)==0){
                    ans.push_back(temp);
                    seen[temp]=1;
                    sz++;
                }

            }
            counter ++;
            if(counter==sz){
                break;
            }
        }

        return ans;
    }
};
