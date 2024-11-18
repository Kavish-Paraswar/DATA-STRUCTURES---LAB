#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
};
struct node *insert(struct node *head, int data, int loc)
{
    if (head == NULL)
    {
        head = create(data);
        return head;
    }
    else
    {
        struct node *p = head, *q = create(data);
        for (int i = 1; i < loc - 1 && p->next != NULL; i++)
        {
            p = p->next;
        }
        q->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = q;
        }
        p->next = q;
        q->prev = p;
    }
    return head;
}
struct node *display(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return head;
};

struct node *delete1(struct node *head, int loc)
{
    struct node *p = head, *q = nullptr;
    if (loc == 1)
    {
        head = p->next;
        head = head->prev;
        free(p);
        return head;
    }
    else
    {
        for (int i = 1; i < loc; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        p->next->prev = q;
        free(p);
        return head;
    }
};
int main()
{
    struct node *head = NULL;
    head = create(10);
    head = insert(head, 20, 2);
    head = insert(head, 30, 3);
    head = insert(head, 99, 4);
    display(head);
    // head = reverse(head);
    // display(head);
    head = delete1(head, 2);
    display(head);
    return 0;
}