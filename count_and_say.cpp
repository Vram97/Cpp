class Solution {
public:

    string cns(string s,int t){
        string ans;
        int count;
        char prev;

        while(t>1){
            ans="";
            count=0;
            prev=s[0];

            for(char x:s){
                // cout<<x<<endl;
                if(prev==x){
                    count++;
                }
                else{
                    // cout<<to_string(count)<<endl;
                    ans+=to_string(count) + prev;
                    count=1;
                    prev=x;
                }
                
            }

            ans+=to_string(count) +prev;
            t--;
            s=ans;
            // cout<<ans<<endl;
        }

        return ans;
    }



    string countAndSay(int n) {
        if(n==1){
            return "1";

        }

        return cns("1",n);
        
    }
};
