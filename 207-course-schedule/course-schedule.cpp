class Solution {
public:
    bool helper(int node, vector<int>& vis, vector<int>& path, vector<vector<int>>& adj){
        vis[node] = 1;
        path[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(helper(it, vis, path, adj)) return true;
            }else if(path[it]) return true;
        }
        path[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<int> vis(V,0);
        vector<int> path(V,-1);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(helper(i, vis, path, adj)) return false;
            }
        }
        return true;
    }
};