class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<int> parent {};
        std::vector<int> rank {};
        parent.reserve(n); rank.reserve(n);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }

        int result {n};
        for (std::vector<int> edge : edges) {
            if (makeUnion(edge[0], edge[1], parent, rank)) {
                --result;
            }
        }
        return result;
    }

    int findParent(int node, std::vector<int>& parent) {
        int result = parent[node];

        while (result != parent[result]) {
            parent[result] = parent[parent[result]];
            result = parent[result];
        }

        return result;
    }
    
    bool makeUnion(int node1, int node2, std::vector<int>& parent, std::vector<int>& rank) {
        node1 = findParent(node1, parent);
        node2 = findParent(node2, parent);

        if (node1 == node2) {
            return false;
        }

        if (rank[node1] > rank[node2]) {
            parent[node2] = node1;
            rank[node1] += rank[node2];
        } else {
            parent[node1] = node2;
            rank[node2] += rank[node1];
        }
        return true;

    }
    
};
