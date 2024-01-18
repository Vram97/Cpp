class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s==""){
            return 0;
        }
        
        int max_len=1;
        int curr_len=0;
        int start=0;
        unordered_map<char,vector<int>>ump;
        const int len=s.length();

        for(int i=0;i<len;i++){
            if(ump.find(s[i])==ump.end()){
                curr_len++;
            }
            else{
                if(ump[s[i]].back()>=start){
                    start=ump[s[i]].back()+1;

                    if(curr_len>max_len){
                        max_len=curr_len;
                    }

                    curr_len=i-start+1;
                }
                else{
                    curr_len++;
                }
            }
            ump[s[i]].emplace_back(i);
            // cout<<curr_len<<endl;
        }

        return (curr_len>max_len)?curr_len:max_len;
    }
};

