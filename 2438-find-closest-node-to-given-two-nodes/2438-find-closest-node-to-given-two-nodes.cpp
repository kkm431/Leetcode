class Solution {
private:
    void dfs(vector<int>& edges, int node1, int dist, vector<int> &d){
        while(node1 != -1 && d[node1] == -1){
            d[node1]= dist++;
            node1= edges[node1];
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // find distance from node1 and node2 to all other nodes
        int n= edges.size();
        vector<int> d1(edges.size(), -1), d2(n, -1);

        dfs(edges, node1, 0, d1);
        dfs(edges, node2, 0, d2);

        int min = INT_MAX, maxDist = -1;
        int res= -1;
         
        for(int i =0; i<n; i++){
            if(d1[i] > -1 && d2[i] > -1){
                maxDist= max(d1[i], d2[i]);

                if(maxDist < min){
                    min = maxDist;
                    res= i;
                }
                
            } 
        }

        return res;

    }
};