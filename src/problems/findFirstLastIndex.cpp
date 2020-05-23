#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if (nums.size() < 1 )return vector<int>()= {-1,-1};
        int index = bsearch(0,nums.size()-1,target,nums);
        if (index ==-1 )return vector<int>()= {-1,-1};
        int l = index; 
        int r = index;
        while(l < nums.size() && nums[l]==target)l--;
        while (r < nums.size() && nums[r]==target)r++;
        return vector<int>() ={l+1,r-1};
    }

    int bsearch(int l, int r , int target, vector<int>&nums)
    {
        if (l > r )return -1;

        int mid = l + (r-l)/2;

        if (nums[mid]==target)return mid;

        if (nums[mid] < target)return bsearch(mid+1,r,target,nums);
        return bsearch (l,mid-1,target,nums);
    }
};
int main()
{
    Solution s ; 
    vector<int> nums = {1};
    int target =1;
    for (auto x : s.searchRange(nums,target)) cout << x << " ";
}