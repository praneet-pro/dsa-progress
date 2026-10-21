class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int curr) {
        visited[curr] = 1;

        for(int i = 0; i < isConnected.size(); i++) {
            if(isConnected[curr][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                dfs(isConnected, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int circle_count = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                circle_count++;

                dfs(isConnected, visited, i);
            }
        }
        return circle_count;
    }
};