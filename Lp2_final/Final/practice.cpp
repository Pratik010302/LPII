#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;

class Graph
{
public:
    map<int, list<int>> adjList;
    map<int, bool> visited;
    queue<int> q;

    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void DFS(int node)
    {
        visited[node] = true;
        std::cout << node << " ";

        for (int i : adjList[node])
        {
            if (!visited[i])
            {
                DFS(i);
            }
        }
    }

    void BFS()
    {
        // Recurse until queue is empty
        if (q.empty())
            return;
        // Pop and assign 1st node in queue
        int node = q.front();
        q.pop();
        // Print node
        cout << node << " ";
        for (int i : adjList[node])
        {
            // If neighbour is not visited add it to queue
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
        BFS();
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 6);

    std::cout << "Enter 0 for DFS nad 1 for BFS" << endl;
    int ch;
    std::cin >> ch;
    if (ch == 0)
    {
        std::cout << "DFS traversal is:" << endl;
        g.DFS(0);
    }
    else
    {
        std::cout << "BFS traversal is:" << endl;
        g.q.push(0);
        g.visited[0] = true;
        g.BFS();
    }

    return 0;
}
