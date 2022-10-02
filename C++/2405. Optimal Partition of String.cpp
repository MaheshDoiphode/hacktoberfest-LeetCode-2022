class Solution {
public:
    int partitionString(string s) {
    
        int ans = 0;
        for(int i=0; i<s.length();i++){
            
            unordered_map<char,int> m;
            while(i<s.length() && m[s[i]]<1){
                m[s[i]]++;
                i++;
            }
            i--;
            ans++;
        }
        return  ans;    
    }   
};