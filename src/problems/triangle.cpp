class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {

        int rows = triangle.size();
        int cols = 0;

        for (int i = rows - 2; i >= 0; i--)
        {
            cols = triangle[i].size();

            for (int j = 0; j < cols; j++)
            {

                triangle[i][j] = cmp(triangle[i][j] + triangle[i + 1][j], triangle[i][j] + triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }

    int cmp(int a, int b)
    {

        if (a > b)
            return b;
        return a;
    }
};