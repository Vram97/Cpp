class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // int count=0;
        unordered_map<int,int> mp;
        vector<int> v;
        int sz=nums.size()/3;
        // vector<int> seen;

        for(int n:nums){
            if(mp.find(n)!=mp.end()){
                mp[n]++;
                if(mp[n]>sz && find(v.begin(),v.end(),n)==v.end()){
                    v.push_back(n);
                }
            }
            else{
                mp[n]=1;
                if(mp[n]>sz && find(v.begin(),v.end(),n)==v.end()){
                    v.push_back(n);
                }
                // seen.push_back(n);
            }

            // count++;
        }
        // count=count/3;

        // for(auto i=mp.begin();i!=mp.end();i++){
        //     if(i->second>count){
        //         v.push_back(i->first);
        //     }

        // }

        return v;
    }
};
