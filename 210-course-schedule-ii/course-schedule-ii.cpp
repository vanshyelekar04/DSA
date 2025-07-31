class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj, vector<int>& ans){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, adj, ans)) return true;
            }else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V =  numCourses;
        vector<vector<int>> adj(V);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(V,0);
        vector<int> pathVis(V,-1);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj, ans)==true) return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};