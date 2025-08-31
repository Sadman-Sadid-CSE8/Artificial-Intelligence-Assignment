#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, int goal, vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << "Visiting: " << node << "\n";

        if (node == goal)
        {
            cout << "Goal found!\n";
            return;
        }

        for (int next : graph[node])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}
int main()
{
    vector<vector<int>> graph = {
        {1, 2}, {3, 4}, {4}, {5}, {5}, {}};
    BFS(0, 5, graph);
}
