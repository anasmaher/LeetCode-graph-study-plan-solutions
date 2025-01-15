class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> vis(n + 1);

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int par = q.front();
            q.pop();

            vis[par] = 1;
            for(int ch : rooms[par]){
                if(!vis[ch]) q.push(ch);
            }
        }

        for(int i = 0; i < n; i++) if(!vis[i]) return false;

        return true;
    }
};
