#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/* Preorder Traversal
Inorder Traversal
Postorder Traversal
Level-wise(BFS) Traversal
Count Leaf Nodes
Count total Leaf nodes /display
Count total number of nodes
Display height of a tree
Display Leaf Nodes
mirror image
*/

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node *));
    p->data = data;
    p->right = nullptr;
    p->left = nullptr;
    return p;
};
struct node *insertNode(struct node *root, int data)
{
    if (root == nullptr)
        return create(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
        if (temp->left == nullptr)
        {
            temp->left = create(data);
            break;
        }
        else
        {
            q.push(temp->left);
        }
        if (temp->right == nullptr)
        {
            temp->right = create(data);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
    return root;
};
// preorder (P-L-R)
void preorder(struct node *T)
{
    if (T == nullptr)
    {
        return;
    }
    stack<node *> s;
    s.push(T);
    while (!s.empty())
    {
        T = s.top();
        s.pop();
        cout << T->data << " ";
        if (T->right)
        {
            s.push(T->right);
        }
        if (T->left)
        {
            s.push(T->left);
        }
    }
}
// POST L-R-P
void postorder(struct node *T)
{
    if (T == nullptr)
    {
        return;
    }
    stack<node *> s;
    struct node *prev = nullptr;
    do
    {
        while (T != nullptr)
        {
            s.push(T);
            T = T->left;
        }
        while (!s.empty())
        {
            T = s.top();
            if (T->right == prev || T->right == nullptr)
            {
                cout << T->data << " ";
                s.pop();
                prev = T;
                T = nullptr;
            }
            else
            {
                T = T->right;
                break;
            }
        }
    } while (!s.empty());
}
// L-P-R
void inorder(struct node *T)
{
    if (T == nullptr)
    {
        return;
    }
    stack<node *> s;
    s.push(T);
    while (!s.empty())
    {
        while (T != nullptr)
        {
            s.push(T);
            T = T->left;
        }
        T = s.top();
        s.pop();
        cout << T->data << " ";
        T = T->right;
    }
}

int count_leaf(struct node *T)
{
    int count = 0;
    if (T == nullptr)
    {
        return count;
    }
    stack<node *> s;
    s.push(T);
    while (!s.empty())
    {
        while (T != nullptr)
        {
            s.push(T);
            T = T->left;
        }
        T = s.top();
        s.pop();
        if (T->left == nullptr && T->right == nullptr)
        {
            cout << T->data << " ";
            count++;
        }
        T = T->right;
    }
    cout << endl;
    return count;
}
int count_nodes(struct node *T)
{
    int count = 0;
    if (T == nullptr)
    {
        return count;
    }
    stack<node *> s;
    s.push(T);
    while (!s.empty())
    {
        while (T != nullptr)
        {
            count++;
            s.push(T);
            T = T->left;
        }
        T = s.top();
        s.pop();
        T = T->right;
    }
    return count;
}
int height(struct node *T)
{
    int height = 0;
    if (T == nullptr)
    {
        return -1;
    }
    queue<node *> q;
    q.push(T);
    while (!q.empty())
    {
        int levelsize = q.size();
        for (int i = 0; i < levelsize; i++)
        {
            T = q.front();
            q.pop();
            if (T->left != nullptr)
            {
                q.push(T->left);
            }
            if (T->right != nullptr)
            {
                q.push(T->right);
            }
        }
        height++;
    }
    return height;
}
void mirror(struct node *T)
{
    if (T == nullptr)
    {
        return;
    }
    stack<node *> s;
    s.push(T);
    while (!s.empty())
    {
        node *current = s.top();
        s.pop();
        swap(current->left, current->right);
        if (current->left != nullptr)
        {
            s.push(current->left);
        }
        if (current->right != nullptr)
        {
            s.push(current->right);
        }
    }
}

void BFS(struct node *T)
{
    if (T == nullptr)
    {
        return;
    }
    queue<node *> q;
    q.push(T);
    while (!q.empty())
    {
        int levelsize = q.size();
        for (int i = 0; i < levelsize; i++)
        {
            T = q.front();
            q.pop();
            cout << T->data << " ";
            if (T->left != nullptr)
            {
                q.push(T->left);
            }
            if (T->right != nullptr)
            {
                q.push(T->right);
            }
        }
    }
}

int main()
{

    struct node *root = nullptr;

    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "No of leaf: ";
    cout
        << count_leaf(root);
    cout << endl;
    cout << "Total leaf nodes: ";
    cout << count_nodes(root);
    cout << endl;
    cout << "Height: ";
    cout << height(root);
    cout << endl;
    cout << "BFS- Level wise traversal: ";
    cout << endl;
    cout << "Mirror image: ";
    mirror(root);
    BFS(root);
    cout << endl;
    return 0;
}