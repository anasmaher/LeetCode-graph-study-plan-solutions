class Solution {
public:
    vector<int> outDeg;
    vector<int> vis;

    bool dfs(vector<vector<int>>& G, int par){
        if(vis[par]) return outDeg[par] == 0;
        vis[par] = 1;

        for(auto ch : G[par]){
            outDeg[par] -= dfs(G, ch);
        }

        return outDeg[par] == 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
        int n = G.size();
        vis.resize(n + 1);
        outDeg.resize(n + 1);

        for(int i = 0; i < n; i++){
            outDeg[i] = G[i].size();
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            dfs(G, i);
            if(outDeg[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};
