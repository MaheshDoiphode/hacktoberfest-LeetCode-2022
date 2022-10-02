
/*
Problem Link : https://leetcode.com/problems/set-matrix-zeroes/
*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &vecc1)
    {
        set<int> colum;
        set<int> row;
        for (int i = 0; i < vecc1.size(); i++)
        {
            for (int j = 0; j < vecc1[0].size(); j++)
            {
                if (vecc1[i][j] == 0)
                {
                    colum.insert(i);
                    row.insert(j);
                }
            }
        }
        for (int i = 0; i < vecc1.size(); i++)
        {
            for (int j = 0; j < vecc1[0].size(); j++)
            {
                if (colum.count(i))
                    vecc1[i][j] = 0;
                if (row.count(j))
                    vecc1[i][j] = 0;
            }
        }
    }
};