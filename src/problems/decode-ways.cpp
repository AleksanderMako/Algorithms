class Solution
{
public:
    int numDecodings(string s)
    {

        int l = s.length();
        vector<int> dp(l + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        if (s[0] == '0' || s.length() == 0)
            return 0;

        for (int i = 2; i < l + 1; i++)
        {

            // check 1 character back
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];

            // check 2 characters back
            if (s[i - 2] != '0' && isAlpha(s, i - 2, 2))
                dp[i] += dp[i - 2];
        }

        return dp[l];
    }
    bool isAlpha(string s, int index, int l)
    {
        string str = s.substr(index, l);
        int digit = stoi(str);
        return (1 <= digit && digit <= 26);
    }
};