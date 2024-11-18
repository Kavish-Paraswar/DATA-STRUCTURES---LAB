#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// void acceptGraph(int adjMatrix[10][10], int vertices)
// {
//     cout << "Enter the adjacency matrix (0 or 1):\n";
//     for (int i = 0; i < vertices; i++)
//     {
//         for (int j = 0; j < vertices; j++)
//         {
//             cin >> adjMatrix[i][j];
//         }
//     }
// }

void displayGraph(int adjMatrix[10][10], int vertices)
{
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(int adjMatrix[10][10], int vertices, int start)
{
    bool visited[10] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal: ";
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (adjMatrix[current][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void DFS(int adjMatrix[10][10], int vertices, int start)
{
    bool visited[10] = {false};
    stack<int> s;

    s.push(start);

    cout << "\nDFS Traversal: ";
    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (!visited[current])
        {
            visited[current] = true;
            cout << current << " ";
        }

        for (int i = vertices - 1; i >= 0; i--)
        {
            if (adjMatrix[current][i] == 1 && !visited[i])
            {
                s.push(i);
            }
        }
    }
    cout << endl;
}

int main()
{
    int vertices = 4;
    int adjMatrix[10][10] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}};

    cout << "Graph with predefined adjacency matrix:\n";
    displayGraph(adjMatrix, vertices);

    int start = 0;

    BFS(adjMatrix, vertices, start);
    DFS(adjMatrix, vertices, start);

    return 0;
}
