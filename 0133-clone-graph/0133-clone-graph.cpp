/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> cloneMap;
        queue<Node*> q;
        q.push(node);

        // Clone the start node
        cloneMap[node] = new Node(node->val);

        // BFS to clone all nodes
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neigh : curr->neighbors) {
                if (!cloneMap.count(neigh)) {
                    cloneMap[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                // Link clone of curr to clone of neighbor
                cloneMap[curr]->neighbors.push_back(cloneMap[neigh]);
            }
        }

        return cloneMap[node];
    }
};
