class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<char>,vector<string>> mp;

        for(auto i:strs){
            vector<char> v(i.begin(),i.end());
            sort(v.begin(),v.end());

            mp[v].push_back(i);

        }

        vector<vector<string>> ans;

        map<vector<char>,vector<string>>::iterator it = mp.begin();

        while(it!=mp.end()){
            ans.push_back(it->second);
            it++;
        }

        return ans;


    }
};
