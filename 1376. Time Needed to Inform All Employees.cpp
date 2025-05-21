class Solution {
public:

    struct Node{
        int node;
        int time;
    };

    vector<vector<Node>> G;
    vector<int> vis;

    int dfs(Node par, int t){
        if(vis[par.node]) return t;
        vis[par.node] = 1;

        int maxTime = t;
        for(Node ch : G[par.node]) 
           maxTime = max(maxTime, dfs(ch, t + ch.time));

        return maxTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        G.resize(n + 1);
        vis.resize(n + 1);

        int head;
        for(int i = 0; i < n; i++){
            if(manager[i] == -1) {
                head = i;
                continue;
            }

            G[manager[i]].push_back({i, informTime[manager[i]]});
        }

        int ans = 0;
        for(Node ch : G[head])
            ans = max(ans, dfs(ch, informTime[head]));

        return ans;
    }
};
