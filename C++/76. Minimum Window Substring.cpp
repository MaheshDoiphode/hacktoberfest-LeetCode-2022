class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        
        // keeping track of common char b/w s ans t
        for(auto i : t)
            mp[i]++;
        
        int start = 0,end =0;   // starting and ending of window
        int minlen = INT_MAX, minstart = 0;
        int count = t.size();   // variable to track when our window becomes valid
        int s_size = s.size();
        
        while(end<s_size)
        {
            
            if(mp[s[end]]>0)    // possible only for char common b/w s and t
                count--;
            
            mp[s[end]]--; // adding char to window and decreasing the mapping
            end++;          //move end forward
            
            while(count==0) // possible answer only here
            {
                if(end - start < minlen)  // window length minimization
                {
                    minlen = end - start;
                    minstart = start;
                }
                
                mp[s[start]]++; // removing char from window and increasing the mapping
                
                if(mp[s[start]]>0)  // possible only for the common chars and hence increase its count to make window invalid
                    count++;
                
                start++;    // move start forward
            }
            
        }
        
        if (minlen != INT_MAX)
		    return s.substr(minstart, minlen);
	    return "";  // happens when s.size() < t.size()
    }
};
