    string getPermutation(int n, int k) {
        string s="";

        for(int i=1;i<n+1;i++){
            s+=to_string(i);
        }

        for(int j=1;j<k;j++){
            next_permutation(s.begin(),s.end());
        }

        return s;
        
    }
};
