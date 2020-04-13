
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Solution
{
public:
    map<string, vector<string>> mostVisitedPattern(vector<string> &username, vector<int> &timestamp, vector<string> &website)
    {
        map<string, vector<string>> m;
        map<string, vector<string>> sequences;
        findSitesByUser(m, username, website);
        return m;
    }

    void findSitesByUser(map<string, vector<string>> &m, vector<string> &username, vector<string> &website)
    {
        for (int i = 0; i < username.size(); i++)
        {
            m[username[i]].push_back(website[i]);
        }
    }
    void build3Seqs(map<string, vector<string>> &sequences, map<string, vector<string>> &m)
    {
        for (auto it = m.begin(); it != m.end(); it++)
        {
        }
    }
    void Getsequence(vector<string> s, map<string, vector<string>> &m, string key)
    {
        vector<string> sequence;
        int start = 0;
        int it=0;
        while (it < s.size())
        {
            if ((s.size()-1)  - (start-1)< 3 )break;
            int size = sequence.size();
            if (size < 3)
                {sequence.push_back(s[start]);it++;}
            if (size == 3)
            {
                m[key] = sequence;
                sequence.clear();
                start++;
                it=start;
            }
        }
    }
};
void printArr(vector<string> a)
{
    for (auto x : a)
        cout << x << " ";
}

int main()
{
    Solution s;
    vector<string> usernames = {"joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary"};
    vector<int> time = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<string> websites = {"home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career"};
    auto m = s.mostVisitedPattern(usernames, time, websites);

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " | ";
        printArr(it->second);
        cout << endl;
    }
}