class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        set<int> s;
        // int count=0;

        for(int x:nums){
            if(mp.find(x)==mp.end()){
                mp[x]++;
                s.insert(x);
            }
            else{
                s.erase(x);
            }
            // mp[nums[i]]++;
        }
        
        vector<int>v(s.begin(),s.end());

        return v;

        // for(int i=0;i<nums.size();i++){
        //     if(mp.find(nums[i])!=mp.end()){
        //         v.erase(v.begin() + mp[nums[i]]);
        //         // count--;
        //         continue;
        //     }
        //     cout<<count<<endl;

        //     v.push_back(nums[i]);
        //     mp[nums[i]]=count;
        //     count++;
            
        // }

        // return v;
    }
};
