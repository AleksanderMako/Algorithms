class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int max = nums[0];
        int max_ending_here = nums[0];
        int min_ending_here = nums[0];
        int prev = 0;

        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        for (int i = 1; i < nums.size(); i++)
        {

            // save max_ending_here in prev before it mutates to use in calulating the min
            prev = max_ending_here;
            max_ending_here = cmp(nums[i], max_ending_here * nums[i]);
            max_ending_here = cmp(max_ending_here, min_ending_here * nums[i]);

            min_ending_here = min(nums[i], nums[i] * min_ending_here);
            min_ending_here = min(min_ending_here, nums[i] * prev);

            max = cmp(max, max_ending_here);
        }
        return max;
    }

    int cmp(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }
    int min(int a, int b)
    {
        if (a > b)
            return b;
        return a;
    }
};