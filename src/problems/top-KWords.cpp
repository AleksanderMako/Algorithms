#include<iostream>
#include<map>
#include<vector>
#include <queue> 
#include<algorithm>

using namespace std;


map<string,int>f;
typedef pair<int,string>ii;
struct  cmp
{
    bool operator ()(const string &s1, const string &s2)
    {
        if(f[s1] == f[s2]) return lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end());
        return f[s1]>f[s2];
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        priority_queue<ii>pq;
        for (auto w : words)f[w]++;
        for (auto it = f.begin(); it != f.end();it++)pq.push(ii(it->second,it->first));

        vector<string >res; 
        while(!pq.empty())
        {
            auto front  = pq.top();pq.pop();
            res.push_back(front.second);
        }
        sort (res.begin(),res.end(),cmp());
        f.clear();
        vector<string>fin;
        for (int i =0 ; i < k; i++)fin.push_back(res[i]);
        return fin;
    }
};


int main()
{
    Solution s ; 
    vector <string>input = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2; 
    auto r = s.topKFrequent(input,k);
    for (auto w:r) cout << w <<" ";
}