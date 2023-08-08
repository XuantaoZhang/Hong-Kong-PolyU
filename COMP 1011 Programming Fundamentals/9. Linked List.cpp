#include <iostream>
using namespace std;

struct Linkedlist
{
    int number;
    Linkedlist *next;
    Linkedlist *previous;
};

void addAtEnd(Linkedlist **head, int value)
{
    Linkedlist *current = *head;
    Linkedlist *newNode = new Linkedlist;

    if (current == NULL)
    {
        newNode->number = value;
        newNode->next = NULL;
        current = newNode;
        *head = current; // Change the head from NULL
    }

    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        newNode->number = value;
        current->next = newNode;
        newNode->next = NULL;
    }
}

void addAtBeginning(Linkedlist **head, int value)
{
    Linkedlist *newNode = new Linkedlist;

    if (*head == NULL)
    {
        newNode->number = value;
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        newNode->number = value;
        newNode->next = *head;
        *head = newNode;
    }
}

bool deleteNthNode(Linkedlist **head, int n)
{
    Linkedlist *current = *head;
    Linkedlist *previous = NULL;

    if (n == 1)
    {
        *head = current->next;
        delete current;
        return true;
    }

    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (current->next != NULL)
            {
                if (i == n)
                {
                    Linkedlist *temp = current->next;
                    current->next = temp->next;
                    delete temp;
                    return true;
                }
                current = current->next;
            }
            else
            {
                return false;
                break;
            }
        }
    }
}

void printList(Linkedlist **head)
{
    Linkedlist *current = *head;
    Linkedlist *previous = NULL;

    while (current != NULL)
    {
        cout << current->number << " ";
        previous = current;
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Linkedlist *head = NULL;
    addAtEnd(&head,4);
    addAtEnd(&head,5);
    addAtEnd(&head,6);
    printList(&head);
    addAtBeginning(&head,3);
    addAtBeginning(&head,2);
    addAtBeginning(&head,1);
    printList(&head);
    deleteNthNode(&head,3);
    printList(&head);
    deleteNthNode(&head,1);
    printList(&head);
    deleteNthNode(&head,1);
    printList(&head);
    deleteNthNode(&head,3);
    printList(&head);
    deleteNthNode(&head,2);
    printList(&head);

    /*Random combination (photoshot)
    addAtBeginning(&head,23);
    addAtBeginning(&head,32);
    addAtEnd(&head,6);
    addAtEnd(&head,623);
    addAtBeginning(&head,-999);
    printList(&head);
    deleteNthNode(&head,2);
    deleteNthNode(&head,3);
    addAtBeginning(&head,-9999);
    addAtEnd(&head,8848);
    printList(&head);*/
    return 0;
}