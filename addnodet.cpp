/*
Description

Using the node definition below, write a function that takes parameters for the three data elements and adds the node
to the end of the linked list. The definition of the Node is in a header file called cpluspluslabs.h that you should
include but not submit it with your solution.

Use this definition for the nodes in the linked list:

class NODE {
  public:
    string firstname;
    string lastname;
    string email;
    NODE* next;
};

Here is an example call to the function

NODE* data = nullptr;

add_node_tail(&data,¡±aspen¡±,¡±olmsted¡±,¡±aspeno@aol.com¡±);

After the above code executes the record will be the only entry in the linked list..

Function Signature

void add_node_tail(NODE** data, string firstname,string lastname, string email);

File Name

addnodet.cpp

Score

There are three test each worth 2 points

Note: You do not need to submit any other code including the main method or any print statements. ONLY the add_node_tail
function is required. Otherwise, the autograder will fail and be unable to grade your code. (I.e., do not include the above
example in your code.) The above example should be used to test your code but deleted or commented out upon submission.
*/

#include "cpluspluslabs.h"
#include <iostream>
#include <string>
using namespace std;


void add_node_tail(NODE** data, string firstname,string lastname, string email)
{
    //create data
    NODE *newNode = new NODE();
    newNode -> firstname = firstname;
    newNode -> lastname = lastname;
    newNode -> email = email;
    newNode -> next = NULL;
    //if NULL then be head
    if(*data == NULL)
    {
        *data = newNode;
        return;
    }
    //find last node
    NODE *lastNode = *data;
    while( lastNode->next!= NULL)
    {
        lastNode = lastNode -> next;
    }
    //insert
    lastNode -> next = newNode;
}

/*
void nodePrint(NODE* n)
{
    while(n != NULL)
    {
        cout<<n->firstname<<" "<<n->lastname<<" "<<n -> email<<endl;
        n = n -> next;
    }
}

int main()
{
    NODE* data = NULL;

    add_node_tail(&data,"aspen","olmsted","aspeno@aol.com");
    add_node_tail(&data,"aspen1","olmsted1","aspeno@aol.com1");
    add_node_tail(&data,"aspen2","olmsted2","aspeno@aol.com2");
    add_node_tail(&data,"aspen3","olmsted3","aspeno@aol.com3");

    nodePrint(data);

    return 0;
}
*/
