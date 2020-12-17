#include <iostream>
#include <stdlib.h>
using namespace std;

#define max 10

typedef struct list
{
    int data;
    struct list *next;
} node;
node *ptr[max], *root[max], *temp[max];

class Dictionary
{
public:
    int index;
    Dictionary();
    void insert(int);
    void search(int);
    void del(int);
};

Dictionary::Dictionary()
{
    index = -1;
    for (int i = 0; i < max; i++)
    {
        root[i] = NULL;
        ptr[i] = NULL;
        temp[i] = NULL;
    }
}

void Dictionary::insert(int key)
{
    index = int(key % max);
    ptr[index] = (node *)malloc(sizeof(node));
    ptr[index]->data = key;
    if (root[index] == NULL)
    {
        root[index] = ptr[index];
        root[index]->next = NULL;
        temp[index] = ptr[index];
    }
    else
    {
        temp[index] = root[index];
        while (temp[index]->next != NULL)
            temp[index] = temp[index]->next;
        temp[index]->next = ptr[index];
    }
}

void Dictionary::search(int key)
{
    int flag = 0;
    index = int(key % max);
    temp[index] = root[index];
    while (temp[index] != NULL)
    {
        if (temp[index]->data == key)
        {
            cout << "Search key found";
            flag = 1;
            break;
        }
        else
            temp[index] = temp[index]->next;
    }
    if (flag == 0)
        cout << "Search key not found";
}

void Dictionary::del(int key)
{
    index = int(key % max);
    temp[index] = root[index];
    while (temp[index]->data != key && temp[index] != NULL)
    {
        ptr[index] = temp[index];
        temp[index] = temp[index]->next;
    }
    ptr[index]->next = temp[index]->next;
    cout << temp[index]->data << " deleted.";
    temp[index]->data = -1;
    temp[index] = NULL;
    free(temp[index]);
}

int main()
{
    int val, ch, n, num;
    char c;
    Dictionary d;
    while (true)
    {
        cout << "\n\nEnter - 1.Create, 2.Search, 3.Delete: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the no. of elements to be inserted: ";
            cin >> n;
            cout << "Enter the elements: ";
            for (int i = 0; i < n; i++)
            {
                cin >> num;
                d.insert(num);
            }
            break;
        case 2:
            cout << "Enter the element to be searched: ";
            cin >> n;
            d.search(n);
            break;
        case 3:
            cout << "Enter the element to be deleted: ";
            cin >> n;
            d.del(n);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}