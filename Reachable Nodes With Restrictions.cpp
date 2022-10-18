/*There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. 

You are also given an integer array restricted which represents restricted nodes.

Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

Note that node 0 will not be a restricted node.

*/

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
	
        vector<int> v[n];    // initialising the graph
		
		//storing the graph
        for(auto it:edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
		
        map<int,int> IsRestricted; // to check whether the node is restricted or not
        
		// storing all the restricted nodes
        for(auto node:restricted){
            IsRestricted [node]  = 1;
        }
		
		// if "0" is restricted, you cannot go to any other nodes, because we start from "0"
        if(IsRestricted [0] > 0 ){
            return 0;
        }
		
		// Doing bfs
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,false);   // for checking if node is already visited or not 
        vis[0] = true;
        int ans = 1;
        while(!q.empty()){
            int parent = q.front();
            q.pop();
            for(auto child : v [parent] ){
				
				//  if node is not visited yet and it is not restricted
                if(!vis[child] and IsRestricted [child] == 0 ){
                    vis[child] = true; // marking node visited
                    ans++;
                    q.push(child);
                }
            }
        }
		
        return ans; // number of reachable nodes
    }
};
