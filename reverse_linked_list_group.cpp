// Reverse a linked list in K groups
#include <bits/stdc++.h> 
using namespace std; 
  
class Node  
{  
    public: 
    int data;  
    Node* next;  
};  
  
Node *reverse (Node *head, int k)  
{  
    Node* current = head;  
    Node* next = NULL;  
    Node* prev = NULL;  
    int count = 0;  
      
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      
    if (next != NULL) head->next = reverse(next, k);  
    return prev;  
}  
  

void push(Node** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 
    new_node->data = new_data;  
    new_node->next = (*head_ref);      
    (*head_ref) = new_node;  
}  
  

void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout << node->data << " ";  
        node = node->next;  
    }  
}  
  
/* Driver code*/
int main()  
{  
    int n, k;
    cout << "Enter N and K, followed by values \n";  
    cin >> n >> k;
    
    Node* head = NULL;
    while(n--){
        int v;
        cin >> v;
        push(&head, v);
    }
  
    cout << "Given linked list \n";  8 4
    printList(head);  
    
    cout << "\nReversed Linked list \n";  
    head = reverse(head, k);  
    printList(head);  
  
    return(0);  
}


// Sample 1
/*
Enter N and K, followed by values
8 4
8 7 6 5 4 2 2 1
Given linked list
1 2 2 4 5 6 7 8
Reversed Linked list
4 2 2 1 8 7 6 5
*/

// Sample 2
/*
Enter N and K, followed by values 
5 3
5 4 3 2 1
Given linked list
1 2 3 4 5
Reversed Linked list
3 2 1 5 4
*/
