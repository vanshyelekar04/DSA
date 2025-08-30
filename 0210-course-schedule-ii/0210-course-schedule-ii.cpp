class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& path,vector<int>& ans, vector<vector<int>>& adj){
        vis[node]=1;
        path[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, path, ans, adj)){
                    return true;
                }
            }else if(path[it]){
                return true;
            }
        }
        path[node]=0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<int> ans;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, vis, path, ans, adj)) return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};