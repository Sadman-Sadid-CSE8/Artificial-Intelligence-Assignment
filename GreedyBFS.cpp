#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, cost;
};

int greedyBestFirstSearch(int start, int goal, vector<vector<Edge>> &graph, vector<int> &heuristic)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({heuristic[start], start});

    vector<bool> visited(graph.size(), false);

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;
        visited[node] = true;

        cout << "Visiting: " << node << "\n";

        if (node == goal)
        {
            cout << "Goal reached!\n";
            return 1;
        }

        for (auto &edge : graph[node])
        {
            if (!visited[edge.to])
            {
                pq.push({heuristic[edge.to], edge.to});
            }
        }
    }
    return 0;
}

int main()
{
    int n = 6;
    vector<vector<Edge>> graph(n);

    graph[0] = {{1, 2}, {2, 4}};
    graph[1] = {{3, 1}, {4, 3}};
    graph[2] = {{4, 2}};
    graph[3] = {{5, 2}};
    graph[4] = {{5, 2}};

    // Heuristic
    vector<int> heuristic = {7, 6, 2, 1, 0, 0};

    greedyBestFirstSearch(0, 5, graph, heuristic);
}
