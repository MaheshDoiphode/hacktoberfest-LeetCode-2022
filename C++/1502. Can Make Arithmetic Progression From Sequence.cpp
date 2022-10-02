class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& vec) {
        
        
        sort(vec.begin() , vec.end());
        
        int diff;
        
        if(vec.size() >=2){
            diff = vec[1]-vec[0];
        }
        
        for(int i=1;i<vec.size()-1 ;i++){
            
            int newDiff  = vec[i+1] - vec[i];
            
            if(newDiff != diff)
            {
                return false;
            }            
            
            
        }
        
        return true;
    }
};