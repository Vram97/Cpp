class Solution {
public:
    void combo(vector<int> temp,int index,int n,int val){
        if(temp.size()==val){
            ans.push_back(temp);
            return;
        }
        // cout<<n<<endl;
        // cout<<val<<endl;

        for(int i=index;i<=n;i++){
            temp.push_back(i);
            combo(temp,i+1,n,val);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        // val=k;
        // n2=n;
        // vector<int
        vector<int> v;
        combo(v,1,n,k);

        return ans;
    }

private:
    vector<vector<int>> ans;
    // int val;
    // int n2;
};
