/*
Description

Modify your earlier implementation of the CSV import function so instead of updating a two
dimensional array it loads the data from the file into a linkedList.

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

csv_import2(&data,¡±customers.csv¡±);

After the above code executes the file contents would be in the linked list.  Contents should
be added in order at the tail of the list.




Function Signature

void csv_import2(NODE** data, string filename);

File Name

csvimport2.cpp

Score

There are five tests each worth 2 points


Note: The csv input file will have 3 columns to match the NODE class. This is different from the
previous implementation that passed the number of columns as a parameter. You do not need to
submit any other code including the main method or any print statements. ONLY the csv_import2
function is required. Otherwise, the autograder will fail and be unable to grade your code.
(I.e., do not include the above example in your code.) The above example should be used to test
your code but deleted or commented out upon submission.
*/



#include "cpluspluslabs.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/*
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
}*/



/*
void csv_import2(NODE** data, string filename)
{

    //array[][]
    string arr[10][3];
    ifstream inFile(filename);

    int n;
    int m=0;
    int row = 0;
    string temp_string;
    string str;
    stringstream word;


    while(inFile>>temp_string)
    {

       word<<temp_string;
        n=0;
        while(getline(word,str,','))
            {
                arr[m][n] = str;
                n++;
            }
        m++;
        if(m>=row){row=m;}

        if(m>=10){break;}
        word.clear();

    }

    inFile.close();


    //LinkedList

    //1. if data = NULL, set headnode;
    int i = 0;

    if(*data == NULL)
    {

        NODE *headNode = new NODE();
        headNode -> firstname = arr[0][0];
        headNode -> lastname = arr[0][1];
        headNode -> email = arr[0][2];

        *data = headNode;
        i = 1;

    }



    while(i<row)
    {
    //2. import current tail node;
    NODE *tailNode = new NODE();
    tailNode -> firstname = arr[i][0];
    tailNode -> lastname = arr[i][1];
    tailNode -> email = arr[i][2];
    tailNode -> next = NULL;

    //3. find current last node;
    NODE *lastNode = *data;
    while( lastNode->next!= NULL)
    {
        lastNode = lastNode -> next;
    }

    //4. insert in current llist;
    lastNode -> next = tailNode;

    i++;

    }

}
*/




void csv_import2(NODE** data, string filename)
{


    ifstream inFile(filename);

    int flag;
    string temp_string;
    string str;
    stringstream word;

    while(inFile>>temp_string)
    {

        word<<temp_string;

                //1. if data = NULL, set headnode;
                flag = 0;
                if(*data == NULL)
                {
                    NODE *headNode = new NODE();

                    while(getline(word,str,','))
                    {
                    if(flag == 0){headNode -> firstname = str;}
                    if(flag == 1){headNode -> lastname = str;}
                    if(flag == 2){headNode -> email = str;}
                    flag++;}

                    *data = headNode;

                }else{

                    NODE *tailNode = new NODE();

                    while(getline(word,str,','))
                    {
                    if(flag == 0){tailNode -> firstname = str;}
                    if(flag == 1){tailNode -> lastname = str;}
                    if(flag == 2){tailNode -> email = str;}
                    tailNode -> next = NULL;
                    flag++;
                    }

                    NODE *lastNode = *data;
                    while( lastNode->next!= NULL)
                        {
                            lastNode = lastNode -> next;
                        }

                    lastNode -> next = tailNode;


                    }

        word.clear();

    }



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

    csv_import2(&data,"customers3.csv");
    csv_import2(&data,"customers4.csv");

    nodePrint(data);

    return 0;
}
*/
