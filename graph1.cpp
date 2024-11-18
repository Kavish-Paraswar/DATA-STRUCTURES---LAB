#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node *A[10];
// Adjacency list
struct node
{
    int vertex;
    struct node *next;
};

void create(struct node *A[])
{
    struct node *p, *temp, *temp2;
    int v1, v2, ch;
    do
    {
        cout << "Enter v1 v2" << endl;
        cin >> v1 >> v2;
        temp = (struct node *)malloc(sizeof(struct node ));
        temp->vertex = v2;
        temp->next = nullptr;
        p = A[v1];
        if (p == nullptr)
        {
            A[v1] = temp;
        }
        else
        {
            while (p->next != nullptr)
            {
                p = p->next;
                p->next = temp;
                temp2 = (struct node *)malloc(sizeof(struct node *));
                temp2->vertex = v1;
                temp2->next = NULL;
                p = A[v2];
                if (p == nullptr)
                {
                    A[v2] = temp2;
                }
                else
                {
                    while (p->next != nullptr)
                    {
                        p = p->next;
                        p->next = temp2;
                    }
                    cout << "Enter 1 : Yes  2 : No" << endl;
                    cin >> ch;
                }
            }
        }
    } while (ch == 1);
};

void BFS(node *a[], int start, int n)
{
    int visited[10] = {0}, v;
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    cout << "\nBFS Traversal: ";
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";

        struct node *p = A[v];
        while (p != nullptr)
        {
            if (!visited[p->vertex])
            {
                visited[p->vertex] = 1;
                q.push(p->vertex);
            }
            p = p->next;
        }
    }
    cout << endl;
}
void display(struct node *A[], int vertices)
{
    cout << "\nAdjacency List Representation:\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << i << " -> ";
        struct node *temp = A[i];
        while (temp != nullptr)
        {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
void DFS(struct node *A[], int start, int vertices)
{
    int visited[10] = {0};
    stack<int> s;
    s.push(start);

    cout << "\nDFS Traversal: ";
    while (!s.empty())
    {
        int v = s.top();
        s.pop();

        if (!visited[v])
        {
            cout << v << " ";
            visited[v] = 1;
        }

        struct node *p = A[v];
        while (p != nullptr)
        {
            if (!visited[p->vertex])
            {
                s.push(p->vertex);
            }
            p = p->next;
        }
    }
    cout << endl;
}
int main()
{
    int vertices, start;
    cout << "Enter the number of vertices (max 10): ";
    cin >> vertices;

    create(A);
    display(A, vertices);

    cout << "Enter starting vertex for BFS traversal: ";
    cin >> start;
    BFS(A, start, vertices);

    cout << "Enter starting vertex for DFS traversal: ";
    cin >> start;
    DFS(A, start, vertices);

    return 0;
}