string convertotobinary(int n)
{
    string s = "";
    while (n > 0)
    {
        s += to_string(n % 2);
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
int concatenatedBinary(int n)
{
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        s += convertotobinary(i);
    }
    long long int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            ans += pow(2, s.length() - i - 1);
            ans = ans % 1000000007;
        }
    }
    return ans;
}