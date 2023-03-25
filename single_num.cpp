class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int x:nums){
            if(mp.find(x)!=mp.end()){
                mp[x]++;
            }
            else{
                mp[x]=1;
            }
        }

        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second==1){
                return i->first;
            }
        }

        return 0;
        
    }
};
