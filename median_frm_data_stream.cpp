class MedianFinder {
public:

    MedianFinder() {
        index=-1;
        
    }
    
    void addNum(int num) {

        if(sw){
            index++;
        }

        if(!v.empty()){
            if(num<=v[0]){
                v.insert(v.begin(),num);
                // cout<<num<<" inex: "<<0<<endl;
            }
            else if(num>=v[len-1]){
                v.emplace_back(num);

                // cout<<num<<" inex: "<<len<<endl;

            }
            else{

                left =0;
                right=len;

                mid=len/2;

                while(true){

                    // if(num==v[mid]){
                    //     v.insert(v.begin()+mid,num);

                    //     // cout<<num<<" inex: "<<mid<<endl;
                        
                    //     break;
                    // }
                    if(mid!=0  && (num<=v[mid] && num>=v[mid-1])){     //&& mid!=len-1

                        v.insert(v.begin()+mid,num);
                            
                        // cout<<num<<" inex: "<<mid<<endl;

                        break;
                    }
                    
                    else if(num<v[mid]){
                        right=mid;
                
                    }
                    else{
                        left=mid;
                    }

                    mid=(left+right)/2;

                }

            }
            
        }
        else{
            v.emplace_back(num);
            // cout<<num<<" 1st element"<<endl;
        }

        len++;
        sw=!sw;
    }
    
    double findMedian() {
        // cout<<index<<endl;
        // sort(v.begin(),v.end());
        // int temp_len=len/2;

        // cout<<temp_len<<endl;

        return(sw)?(double)(v[index] +v[index+1])/2 : v[index];
        
    }

private:
    vector<int> v;
    int len=0;
    int index;
    bool sw=true;
    int left=0;
    int right=0;
    int mid=0;

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
