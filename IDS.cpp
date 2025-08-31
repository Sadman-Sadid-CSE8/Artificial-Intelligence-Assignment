#include <iostream>
#include <vector>
using namespace std;

bool DLS(int node, int goal, int depth, vector<vector<int>> &graph)
{
    cout << "Visiting: " << node << " at depth " << depth << "\n";
    if (node == goal)
    {
        cout << "Goal found!\n";
        return true;
    }
    if (depth == 0)
        return false;

    for (int next : graph[node])
    {
        if (DLS(next, goal, depth - 1, graph))
            return true;
    }
    return false;
}

void IDS(int start, int goal, vector<vector<int>> &graph, int maxDepth)
{
    for (int depth = 0; depth <= maxDepth; depth++)
    {
        cout << "---- Depth Limit = " << depth << " ----\n";
        if (DLS(start, goal, depth, graph))
            return;
    }
    cout << "Goal not found within depth limit\n";
}

int main()
{
    vector<vector<int>> graph = {
        {1, 2}, {3, 4}, {4}, {5}, {5}, {}};
    IDS(0, 5, graph, 5);
}
