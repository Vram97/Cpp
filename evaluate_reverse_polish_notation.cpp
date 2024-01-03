class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        vector<string> operators{"+","-","*","/"};

        const int sz=tokens.size();
        // int curr=0;

        for(int i=0;i<sz;i++){
            if(find(operators.begin(),operators.end(),tokens[i])!=operators.end()){
                int val1=nums.top();
                nums.pop();
                int val2=nums.top();
                nums.pop();

                if(tokens[i]=="-"){
                    nums.push(val2-val1);
                }
                else if(tokens[i]=="+"){
                    nums.push(val1+val2);
                }
                else if(tokens[i]=="*"){
                    nums.push(val1*val2);
                }
                else{
                    nums.push(val2/val1);
                }
            }
            else{
                // curr=stoi(num);
                nums.push(stoi(tokens[i]));
            }

        }

        return nums.top();
    }


};
