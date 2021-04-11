#include <iostream>
using namespace std;

class Node
{
    public:

    int value;
    Node* next;

};

void printList(Node *n)
{
    while( n != NULL)
    {
        cout<<n->value<<endl;
        n = n -> next;
    }
}

void insertAtTheFront(Node** head, int newValue)
{
    //create a new node in dynamic memory;
    Node* newNode = new Node();
    newNode -> value = newValue;
    //
    newNode -> next = *head;
    //
    *head = newNode;
}

void insertAtTheEnd(Node** head, int newValue)
{
    //create new node in dynamic memory
    Node* newNode = new Node();
    newNode -> value = newValue;
    newNode -> next = NULL;
    //if empty, be the head
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    //find the last node
    Node* last = *head;
    while( last -> next!= NULL)
    {
        last = last -> next;
    }
    //insert to last
    last ->next = newNode;

}

/*
void insertAtTheEnd2(Node* head, int newValue)
{
    //create new node in dynamic memory
    Node* newNode = new Node();
    newNode -> value = newValue;
    newNode -> next = NULL;
    //if empty, be the head
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    //find the last node
    Node* last = head;
    while( last -> next!= NULL)
    {
        last = last -> next;
    }
    //insert to last
    last ->next = newNode;

}*/


void insertAfter(Node*previousNode, int newValue)
{
    //if NULL
    if(previousNode == NULL)
    {
        cout<<"Previous node is NULL!";
        return;
    }
    //create new node
    Node *newNode = new Node();
    newNode -> value = newValue;
    //insert
    newNode -> next = previousNode -> next;
    previousNode -> next = newNode;

}


int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head -> value = 1;
    head -> next = second;
    second -> value = 2;
    second -> next = third;
    third -> value = 3;
    third -> next = NULL;


    insertAtTheFront(&head, -1);
    insertAtTheEnd(&head, 4);
    //insertAtTheEnd2(head, 4);
    insertAfter(second,-2);


    printList(head);

}


