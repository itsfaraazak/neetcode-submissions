class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        
        std::unordered_map<int, std::vector<int>> adjacencyList = prepareAdjacencyList(edges);

        std::unordered_set<int> visited {};
        if (dfsHasCycle(n, adjacencyList, 0, -1, visited)) {
            return false;
        }
        return visited.size() == n; 
    }

    std::unordered_map<int, std::vector<int>> prepareAdjacencyList(const std::vector<std::vector<int>>& edgesList) {
        std::unordered_map<int, std::vector<int>> adjacencyList {};
        for (std::vector<int> edge : edgesList) {
            if (adjacencyList.find(edge[0]) == adjacencyList.end()) {
                adjacencyList[edge[0]] = {edge[1]};
            } else {
                adjacencyList[edge[0]].push_back(edge[1]);
            }
            if (adjacencyList.find(edge[1]) == adjacencyList.end()) {
                adjacencyList[edge[1]] = {edge[0]};
            } else {
                adjacencyList[edge[1]].push_back(edge[0]);
            }
        }
        return adjacencyList;
    }

    bool dfsHasCycle(int n, std::unordered_map<int, std::vector<int>>& adjacencyList, int currentEdge, int prevEdge, std::unordered_set<int>& visited) {
        if (visited.find(currentEdge) != visited.end()) {
            return true;
        }
        visited.insert(currentEdge);

        for (int vertex : adjacencyList[currentEdge]) {
            if (vertex == prevEdge) {
                continue;
            }
            if (dfsHasCycle(n, adjacencyList, vertex, currentEdge, visited)) {
                return true;
            }
        }
        return false;
    }
};
