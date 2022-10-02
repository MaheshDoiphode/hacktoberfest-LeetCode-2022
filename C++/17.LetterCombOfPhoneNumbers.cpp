// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Solution-

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};

        string op="";
        vector<string> res;
        solve(digits,op,res);
        return res;
    }

    void solve(string digits,string op,vector<string> &res)
    {
        vector<string> v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if(digits.size()==0) 
        {
            res.push_back(op);
            return;
        }


        string s = v[digits[0] - '0'];   
        digits.erase(digits.begin()+0);

        for(int i=0;i<s.length();i++)
        { 
            solve(digits,op+s[i],res);
        }
    }
};
