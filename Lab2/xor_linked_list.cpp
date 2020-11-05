#include <bits/stdc++.h>
#include <inttypes.h>

using namespace std;

class Node
{
public:
    int data;
    Node *npx;
};

Node *XOR(Node *a, Node *b)
{
    return (Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insertFirst(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;

    new_node->npx = *head;

    if (*head != NULL)
        (*head)->npx = XOR(new_node, (*head)->npx);

    *head = new_node;
}

void insertLast(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    Node *curr = *head;
    Node *prev = NULL;
    Node *next;

    while (XOR(prev, curr->npx) != NULL)
    {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }

    new_node->npx = curr;
    curr->npx = XOR(prev, new_node);
}

void printList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    cout << "XOR Linked List: ";

    while (curr != NULL)
    {
        cout << curr->data << " ";
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    cout << "\n\n";
}

int main()
{
    Node *head = NULL;

    while (true)
    {
        char where;
        cout << "Where do you want to insert, f for first, l for last: ";
        cin >> where;

        if (where == 'f')
        {
            cout << "Insert element at first: ";
            int val;
            cin >> val;
            insertFirst(&head, val);
            printList(head);
        }
        else if (where == 'l')
        {
            cout << "Insert element at last: ";
            int val;
            cin >> val;
            insertLast(&head, val);
            printList(head);
        }
        else
        {
            printList(head);
            break;
        }
    }
}