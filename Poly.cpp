#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node *create(struct node *head, int coef, int exp)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
};

struct node *add(struct node *head1, struct node *head2)
{
    struct node *p = head1;
    struct node *q = head2;
    struct node *result = NULL;
    while (p != NULL || q != NULL)
    {
        if (p->exp == q->exp)
        {
            result = create(result, p->coef + q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            result = create(result, p->coef, p->exp);
            p = p->next;
        }
        else
        {
            result = create(result, q->coef, q->exp);
            q = q->next;
        }
    }
    while (p != NULL) {
        result = create(result, p->coef, p->exp);
        p = p->next;
    }
    while (q != NULL) {
        result = create(result, q->coef, q->exp);
        q = q->next;
    }
    return result;
}
void display(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        cout << p->coef << "X^" << p->exp;
        p = p->next;
        if (p != NULL)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

int main()
{
    struct node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

    // Creating first polynomial 6x^3 + 5x^2 + 4x^1
    poly1 = create(poly1, 6, 3);
    poly1 = create(poly1, 5, 2);
    poly1 = create(poly1, 4, 1);

    // Creating second polynomial 4x^3 + 3x^2 + 2x^1
    poly2 = create(poly2, 4, 3);
    poly2 = create(poly2, 3, 2);
    poly2 = create(poly2, 2, 1);

    poly3 = add(poly1, poly2);
    cout << "Sum of Polynomials: ";
    display(poly3);

    return 0;
}
