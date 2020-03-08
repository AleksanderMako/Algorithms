#include<vector>
#include<iostream>
#include<queue>
using namespace std;
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for (auto s : sticks)pq.push(s);

       int c_sofar=0;
        while (!pq.empty() && pq.size()>1)
        {
            int front = pq.top();pq.pop();
            int second = pq.top();pq.pop();
            int sum=front+second;
            c_sofar +=sum;
            pq.push(sum);
        }
        return c_sofar;
    }
};

int main()
{
    Solution s ;
    vector<int> sticks = {3354,4316,3259,4904,4598,474,3166,6322,8080,9009};
    cout << s.connectSticks(sticks);
}