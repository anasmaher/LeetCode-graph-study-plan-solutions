class Solution {
public:
    struct Node{
        int node;
        char color;

        bool operator<(const Node& other) const {
            return (node < other.node) || (node == other.node && color < other.color);
        }
    };

    vector<vector<Node>> G;

    vector<int> bfs(int n){
        queue<Node> q;
        q.push({0, 'z'});
        
        map<Node, int> dist;
        dist[{0, 'z'}] = 0;

        while(!q.empty()){
            Node cur = q.front();            
            q.pop();
            
            for(auto ch : G[cur.node]){
                if(ch.color != cur.color && dist[ch] == 0) {
                    dist[ch] = 1 + dist[cur];

                    q.push(ch);
                }
            }
        }
        
        vector<int> ans(n, 1e9);
        for(auto [f, s] : dist){
            ans[f.node] = min(ans[f.node], s);
        }

        for(int i = 0; i < n; i++) if(ans[i] == 1e9) ans[i] = -1;
        return ans;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int x = redEdges.size(), y = blueEdges.size();

        G.resize(n);

        for(int i = 0; i < x; i++){
            G[redEdges[i][0]].push_back({redEdges[i][1], 'r'});
        }
        for(int i = 0; i < y; i++){
            G[blueEdges[i][0]].push_back({blueEdges[i][1], 'b'});
        }

        return bfs(n);
    }
};
