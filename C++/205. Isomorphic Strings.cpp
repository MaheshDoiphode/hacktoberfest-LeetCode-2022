class Solution {
public:
    bool isIsomorphic(string s, string t) {
             unordered_map<char, int> m1, m2;
        string s1="", s2="";
        int count = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(m1[s[i]] != 0)
            {
                s1 += m1[s[i]];
            }
            else
            {
                s1 += char('a' + count);
                 m1[s[i]] = char('a'+ count);
                count++;
            }
        }
         count = 0;
        
         for(int i=0; i<t.length(); i++)
        {
            if(m2[t[i]] != 0)
            {
                s2 += m2[t[i]];
            }
            else
            {
                s2 += char('a' + count);
                 m2[t[i]] = char('a'+ count);
                count++;
            }
        }
        
  
        return s1==s2;
    }
};