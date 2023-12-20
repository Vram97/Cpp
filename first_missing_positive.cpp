class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        set<int> s;
        const int sz=nums.size();

        for(int &n:nums){
            if(n>0 && n<=sz]){
                s.insert(n);
            }
        }

        int ans=1;

        for(set<int>::iterator it=s.begin();it!=s.end();it++){
            if(*it==ans){
                ans++;
            }
            else{
                return ans;
            }
        }
        return ans;
        
    }
};
