/*
Description

Using the node definition below, write a function that takes parameters for the three data elements and adds the
node to the beginning of the linked list. The definition of the Node is in a header file called cpluspluslabs.h
that you should include but not submit it with your solution.

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

add_node_head(&data,¡±aspen¡±,¡±olmsted¡±,¡±aspeno@aol.com¡±);

add_node_head(&data,¡±sally¡±,¡±jones¡±,¡±sjones@aol.com¡±);

After the above code executes there will be two records in the linked list with Sally¡¯s recording coming first..




Function Signature

void add_node_head(NODE** data, string firstname,string lastname, string email);

File Name

addnodeh.cpp

Score

There are three tests each worth 2 points

Note: You do not need to submit any other code including the main method or any print statements. ONLY the add_node_head
function is required. Otherwise, the autograder will fail and be unable to grade your code. (I.e., do not include the
above example in your code.) The above example should be used to test your code but deleted or commented out upon submission.
*/
#include "cpluspluslabs.h"
#include <iostream>
#include <string>
using namespace std;

/*
void printLList(NODE *data)
{
    while( data != NULL)
    {
        cout<<data -> firstname<<" "<<data -> lastname<<" "<<data -> email<<endl;
        data = data->next;
    }
}*/

void add_node_head(NODE** data, string firstname,string lastname, string email)
{
    //create
    NODE* newNode = new NODE();
    newNode -> firstname = firstname;
    newNode -> lastname = lastname;
    newNode -> email = email;
    //insert
    newNode -> next = *data;
    *data = newNode;
}

/*
int main()
{

    NODE* data = NULL;

    add_node_head(&data, "aspen","olmsted","aspeno@aol.com");
    add_node_head(&data, "sally","jones","sjones@aol.com");
    add_node_head(&data,"sally4","jones4","sjones@aol.com4");
    add_node_head(&data,"sally20","jones10","sjones@aol.com70");

    printLList(data);

    return 0;

}*/



























