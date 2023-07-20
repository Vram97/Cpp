class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int sz=asteroids.size();
        // count=0;
        int i=0;

        while(i<sz){
            if(asteroids[i]>0 && i!=sz-1){
                if(asteroids[i+1]<0){
                    if(-asteroids[i+1]>asteroids[i]){
                        asteroids.erase(asteroids.begin()+i);
                        sz--;

                    }
                    else if(-asteroids[i+1]<asteroids[i]){
                        asteroids.erase(asteroids.begin()+i+1);
                        sz--;
                    }
                    else{
                        asteroids.erase(asteroids.begin()+i);
                        asteroids.erase(asteroids.begin()+i);
                        sz-=2;
                    }
                }
                else{
                    i++;
                }
            }
            else if(asteroids[i]<0 && i!=0){
                if(asteroids[i-1]>0){
                    if(asteroids[i-1]>-asteroids[i]){
                        asteroids.erase(asteroids.begin()+i);
                        sz--;
                    }
                    else if(asteroids[i-1]<-asteroids[i]){
                        asteroids.erase(asteroids.begin()+i-1);
                        sz--;
                        i--;
                    }
                    else{
                        asteroids.erase(asteroids.begin()+i);
                        asteroids.erase(asteroids.begin()+i-1);
                        i--;
                        sz-=2;
                    }
                }
                else{
                    i++;
                }
            }
            else{
                i++;
            }
        }

        return asteroids;
        
    }
};
