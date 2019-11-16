class Solution
{
public:
    int rob(vector<int> &nums)
    {

        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(), 0);
        map<int, int> robbed;

        dp[0] = nums[0];
        dp[1] = cmp(nums[0], nums[1]);

        if (nums.size() == 2)
            return cmp(dp[0], dp[1]);
        if (nums.size() == 3)
            return cmp(cmp(nums[2], nums[1]), nums[0]);
        if (nums.size() == 4)
            return cmp(nums[3] + nums[1], nums[2] + nums[0]);

        int m1 = 0;
        int m2 = 0;

        for (int i = 2; i < nums.size() - 1; i++)
        {

            dp[i] = cmp(dp[i - 1], nums[i] + dp[i - 2]);
            m1 = cmp(m1, dp[i]);
        }

        dp.clear();
        dp[1] = nums[1];
        dp[2] = cmp(nums[1], nums[2]);

        for (int i = 3; i < nums.size(); i++)
        {
            dp[i] = cmp(dp[i - 1], nums[i] + dp[i - 2]);
            m2 = cmp(m2, dp[i]);
        }
        return cmp(m1, m2);
    }
    int cmp(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }
};