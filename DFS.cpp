#include <iostream>
#include <vector>
using namespace std;

bool DFSUtil(int node, int goal, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    cout << "Visiting: " << node << "\n";

    if (node == goal)
    {
        cout << "Goal found!\n";
        return true;
    }

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            if (DFSUtil(next, goal, graph, visited))
                return true;
        }
    }
    return false;
}

void DFS(int start, int goal, vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    DFSUtil(start, goal, graph, visited);
}

int main()
{
    vector<vector<int>> graph = {
        {1, 2}, {3, 4}, {4}, {5}, {5}, {}};
    DFS(0, 5, graph);
}
