vector<vector<int>> palindromePairs(vector<string> &words)
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<vector<int>> ans = palindromePairs(words);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}