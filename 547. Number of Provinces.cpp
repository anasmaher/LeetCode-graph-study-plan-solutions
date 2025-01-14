class Solution {
public:
    vector<int> vis;
    vector<vector<int>> G;

    int ans = 0;
    
    void dfs(int par){
        if(vis[par]) return;
        vis[par] = 1;

        for(int ch : G[par]){
            dfs(ch);
        }
    }

    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();

        vis.resize(n, 0);
        G.resize(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j]){
                    G[i].push_back(j);
                } 
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }

        return ans;
    }
};
