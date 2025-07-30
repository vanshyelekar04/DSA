class Solution {
public:
bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& ans){
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfsCheck(it,adj, vis, pathVis, ans)) return true;
        }else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node] = 0;
    ans.push_back(node);
    return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> vis(numCourses, 0), pathVis(numCourses, 0);
        vector<int> ans;
        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
                if(dfsCheck(i, adj, vis, pathVis, ans)){
                    return {};
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};