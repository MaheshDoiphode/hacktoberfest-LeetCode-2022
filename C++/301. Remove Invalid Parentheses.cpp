class Solution {
public:
    vector<string> ans;
    unordered_set<string> uset; 
    int countRemoval(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(st.size()==0){
                    st.push(')');
                }
                else if(st.top()==')'){
                    st.push(')');
                }
                else if(st.top()=='('){
                    st.pop();
                }
            }
        }
        
        return st.size();
    }
   
    void helper(int invalid,string s){
        if(invalid<0) return;
        if(invalid==0){ 
            int invalidNow=countRemoval(s);
            if(invalidNow==0){
                ans.push_back(s);
            }
            return;
        }
      for(int i=0;i<s.size();i++){
          if (s[i] != ')' && s[i] != '(') continue;
          
          string left=s.substr(0,i);
          string right=s.substr(i+1);
          string temp=left+right;
          if(uset.find(temp)==uset.end()){
              uset.insert(temp);
            helper(invalid-1,temp);       
          }
               
      }  
    }
    vector<string> removeInvalidParentheses(string s) {
        int invalid=countRemoval(s);
        helper(invalid,s);
        return ans;
    }
};
