class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        // vector<char> vec;
        // vector<int> index;

        int sz=secret.size();
        int cow=0;
        int bull=0;
        // count=0;

        for(int i=0;i<sz;i++){
            if(secret[i]==guess[i]){
                bull++;
                
                // index.emplace_back(i);
            }


            mp[secret[i]]++;
        }

        for(int j=0;j<sz;j++){
            if(mp.find(guess[j])!=mp.end()){
                cout<<guess[j]<<endl;
                cow++;
                mp[guess[j]]--;

                if(mp[guess[j]]==0){
                    mp.erase(guess[j]);
                }
            }
        }
        cow=cow-bull;

        // int bull=0;
        // int cow=0;

        // for(int j=0;j<sz;j++){
        //     if(mp.find(guess[j])!=mp.end()){
        //         if(mp[guess[j]]==j){
        //             bull++;
        //         }
        //         else{
        //             cow++;
        //         }
        //     }
        // }

        return to_string(bull)+"A"+to_string(cow)+"B";
        
    }
};
