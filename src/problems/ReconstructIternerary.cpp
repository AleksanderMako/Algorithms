class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>trips;
    vector<string>path;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
       for (int i =0 ; i < tickets.size();i++)
       {
           trips[tickets[i][0]].push(tickets[i][1]);
       }
        dfs("JFK");
         reverse(path.begin(), path.end());
        return path;
    }
    
    void dfs(string start)
    {
        auto & neighbors = trips[start];
        
        while(!neighbors.empty())
        {
            string top = neighbors.top();neighbors.pop();
            
            dfs(top);
        }
        path.push_back(start);
    }
    
    
};