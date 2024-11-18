#include <iostream>
#include <queue>
#include <stack>

// INSERTION(all cases)
// Deletion(all cases)
// Mirror
// BST
// NO of leaf nodes and display
// NO of total nodes and display
// Height
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
struct node *create(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->right = nullptr;
    temp->left = nullptr;
    temp->data = data;
    return temp;
}
struct node *insertNode(struct node *T, int data)
{
    if (T == nullptr)
    {
        return create(data);
    }
    struct node *child = T, *parent = nullptr, *temp = create(data);
    while (child != NULL)
    {
        if (data < child->data)
        {
            parent = child;
            child = child->left;
        }
        else
        {
            parent = child;
            child = child->right;
        }
    }
    if (data < parent->data)
    {
        parent->left = temp;
    }
    else
    {
        parent->right = temp;
    }

    return T;
};
struct node *findsuc(struct node *T)
{

    T = T->right;
    while (T && T->left != nullptr)
    {
        T = T->left;
    }
    return T;
}
struct node *deleteBST(struct node *T, int data)
{
    if (T == nullptr)
    {
        return T;
    }
    if (data > T->data)
    {
        T->right = deleteBST(T->right, data);
    }
    else if (data < T->data)
    {
        T->left = deleteBST(T->left, data);
    }
    else
    {

        if (T->left == nullptr)
        {
            struct node *temp = T->right;
            free(T);
            return temp;
        }
        else if (T->right == nullptr)
        {
            struct node *temp = T->left;
            free(T);
            return temp;
        }
        struct node *temp = findsuc(T);
        T->data = temp->data;
        T->right = deleteBST(T->right, temp->data);
    }
    return T;
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
        node *current = nullptr;
        int levelsize = q.size();
        for (int i = 0; i < levelsize; i++)
        {
            current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }
}
int height(struct node *T)
{
    int height = 0;
    queue<node *> q;
    q.push(T);
    while (!q.empty())
    {
        node *current = nullptr;
        int levelsize = q.size();
        for (int i = 0; i < levelsize; i++)
        {
            current = q.front();
            q.pop();
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
        height++;
    }
    return height;
}

struct node *copytree(struct node *T)
{
    if (T == nullptr)
        return T;
    struct node *newnode = nullptr;
    queue<node *> q;
    q.push(T);
    while (!q.empty())
    {
        node *origin = q.front();
        q.pop();
        newnode = insertNode(newnode, origin->data);
        if (origin->left != nullptr)
        {
            q.push(origin->left);
        }
        if (origin->right != nullptr)
        {
            q.push(origin->right);
        }
    }
    return newnode;
}
// NOt distrub the original tree
void mirror(struct node *T)
{
    if (T == nullptr)
        return;
    stack<node *> s;
    s.push(T);
    struct node *temp = nullptr;
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        swap(temp->left, temp->right);
        if (temp->left != nullptr)
        {
            s.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            s.push(temp->right);
        }
    }
}

int main()
{
    struct node *root = nullptr;
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);

    cout << "Tree before deletion:" << endl;
    BFS(root);
    cout << endl;
    root = deleteBST(root, 5);
    root = deleteBST(root, 1);

    cout << "Tree after deletion:" << endl;
    BFS(root);
    cout << endl
         << "Height " << height(root) << endl;
    struct node *mirror_tree = copytree(root);
    mirror(mirror_tree);
    cout << endl
         << "Mirror is " << endl;
    BFS(root);

    return 0;
}