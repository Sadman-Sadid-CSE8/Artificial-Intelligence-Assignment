#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int to, cost;
};

void UCS(int start, int goal, vector<vector<Edge>> &graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(graph.size(), INT_MAX);

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();
        cout << "Visiting: " << node << " with cost=" << cost << "\n";

        if (node == goal)
        {
            cout << "Goal found! Total cost = " << cost << "\n";
            return;
        }

        for (auto &e : graph[node])
        {
            int newCost = cost + e.cost;
            if (newCost < dist[e.to])
            {
                dist[e.to] = newCost;
                pq.push({newCost, e.to});
            }
        }
    }
}
int main()
{
    vector<vector<Edge>> graph = {
        {{1, 2}, {2, 4}}, {{3, 1}, {4, 3}}, {{4, 2}}, {{5, 2}}, {{5, 2}}, {}};
    UCS(0, 5, graph);
}
