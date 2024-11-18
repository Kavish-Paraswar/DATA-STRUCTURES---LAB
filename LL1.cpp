#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *create(int n)
{
    // int value;
    // struct node *head, *p;
    // head = (struct node *)malloc(sizeof(struct node));
    // cout << "1st element" << endl;
    // cin >> value;
    // head->data = value;
    // head->next = NULL;
    // p = head;
    // for (int i = 1; i < n; i++)
    // {
    //     p->next = (struct node *)malloc(sizeof(struct node));
    //     p = p->next;
    //     cin >> p->data;
    //     p->next = NULL;
    // }
    // return head;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = n;
    p->next = NULL;
    return p;
};


void display(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
};

struct node *insert(struct node *head, int val, int loc)
{
    struct node *p, *q;
    q = (struct node *)malloc(sizeof(struct node *));
    q->data = val;
    q->next = NULL;
    if (loc == 1)
    {
        q->next = head;
        head = q;
        return head;
    }
    else
    {
        p = head;
        for (int i = 1; i < loc - 1; i++)
        {
            p = p->next;
            if (p == NULL)
            {
                return head;
            }
        }
        q->next = p->next;
        p->next = q;
        return head;
    }

    return head;
}
struct node *delete1(struct node *head, int val, int loc)
{
    if (head == NULL)
    {
        return head;
    }
    struct node *p = head, *q;
    if (loc == 1)
    {
        head = head->next;
        free(p);
    }
    while (p->data != val)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        return head;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return head;
};
struct node *reverse(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct node *prev = nullptr;
    struct node *current = head;
    struct node *next = nullptr;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
};

int main()
{
    int n;
    struct node *head;
    cin >> n;
    head = create(n);
    display(head);
    head = insert(head, 99, 3);
    display(head);
    // head = reverse(head);
    // display(head);
    head = delete1(head, 99, 3);
    display(head);
    return 0;
}
