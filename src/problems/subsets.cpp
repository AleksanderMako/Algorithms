#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>currentset;
        vector<vector<int>>solutionSet;
        solutionSet.push_back(currentset);
        makeset(nums,0,currentset,solutionSet);
        return solutionSet;
    }
    void makeset(vector<int>&nums,int j, vector<int>&setSofar,vector<vector<int>>&solutionSet)
    {
       
            solutionSet.push_back(setSofar);
       
        for (int i =j ; i < nums.size();i++)
        {

            setSofar.push_back(nums[i]);
            makeset(nums,i+1,setSofar,solutionSet);

            setSofar.pop_back();
        }

    }
};
int main()
{
    vector<int>test = {1,2,3};
    Solution s;
    auto res = s.subsets(test);

    for (auto v : res)
    {
        for( auto i: v)
        {
            cout << i << " ";
        }
        cout <<endl;
    }
}