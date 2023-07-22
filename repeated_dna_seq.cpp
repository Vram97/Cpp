class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string>ans;

        // cout<<(int)s.length()-10<<endl;

        for(int i=0;i<=(int)s.length()-10;i++){
            // cout<<s<<endl;
            const string temp=s.substr(i,10);
            mp[temp]++;

            if(mp[temp]==2){
                ans.emplace_back(temp);
            }
        }

        return ans;
        
    }
};
