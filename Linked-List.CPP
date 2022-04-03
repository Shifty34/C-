#include <iostream>
#include <string>
#include <cstring> 
using namespace std;

class Node {

public:

string data;

Node* next;

// Default constructor

Node() {

data = " ";

next = NULL;

}

// Parametrized Constructor

Node(string data){

this->data = data;

this->next = NULL;

}

}; //end of Node

// Linked list class to

// implement a linked list.

class Linkedlist{

public:

Node* head;


Linkedlist() { head = NULL; }

void printList();
void printListEX(char t);
void deleteNode(int p);

void insertNode(string Element){

  Node* newNode = new Node();
  

  newNode->data = Element;
  

  newNode->next = NULL; 
  
 
  if(head == NULL) {
    head = newNode;
  } else {
    

    Node* temp = head;
    while(temp->next != NULL)
      temp = temp->next;
    

    temp->next = newNode;
  }    


}


void insertNodePos(string data, int pos){

Node * pre = new Node();
Node * cur = new Node();
Node * newNode = new Node();
newNode->data = data;

int temppos = 0; 

cur = head;

if(head != NULL)
  {
    while(cur->next != NULL && temppos != pos)
    {
        pre = cur;
        cur = cur->next;
        temppos++;
    }
    if(pos==0)
    {
       cout << "Adding at Head! " << endl;
     
    }
    else if(cur->next == NULL && pos == temppos+1)
    {
      cout << "Adding at Tail! " << endl;
      
    }
    else if(pos > temppos+1)
      cout << " Position is out of bounds " << endl;


    else
    {
        pre->next = newNode;
        newNode->next = cur;
    }
 }
 else
 {
    head = newNode;
    newNode->next=NULL;
    cout << "Added at head as list is empty! " << endl;
 }
}

void deleteNodeC(char o);



};







void Linkedlist::printList() {

Node * n = new Node();
n = head;





if(n == NULL) {
cout << "Empty" << endl;
}

while(n != NULL){

cout << n->data << "->";

n = n->next;


}
}


void Linkedlist::printListEX(char t)
{
    Node* n = head;

    if (n == NULL) {
        cout << "Empty" << endl;
    }

    while (n != NULL) {
        if ((n->data).find(t) != string::npos) 
        {
            cout << n->data << "->";
        }
        n = n->next; 
    }
}


void Linkedlist::deleteNode(int p){

Node * D = new Node();
D = head;


if (D == NULL){
        return;
      }

  

    if (p == 0)
    {
          

        D = D->next; 
          

        free(D);             
        return;
    }
  

    for(int i = 0; D != NULL && i < p - 1; i++) {
        D = D->next;
  }

    if (D == NULL || D->next == NULL){
        return;
  }
    
     Node *next = D->next->next;
  
    free(D->next); 
      

     D->next = next; 
}

void Linkedlist::deleteNodeC(char o){

Node* le = new Node(); 
Node* ri = new Node();
Node* del = new Node();

le = NULL;
ri = head;

while(ri != NULL){
      if(ri->data.find(o) != string::npos){
       del = ri;
      
    
    if(le==NULL){
    head = head->next;
    }  else{
    le->next = del->next;
    }
    
    ri = del->next;
    
    delete del;
    
    } else {
    le = ri;
    ri = ri->next;
    }

}

}




int main() {


string Name;
	/*****************************************/
cout << "Student Enter Name" << endl;
cin >> Name;
cout << "----------------------------------------------" << endl;
cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
cout << "Student Name: " << Name << endl;
cout << "----------------------------------------------" << endl;
	/*****************************************/

Linkedlist l;
char r = 'r';
char o = 'o';
string animals[] = {"dog", "cat", "mammal", "rat", "lion", "frog", "monkey", "tiger", "snake",
"horse", "mouse", "hog", "bat", "deer", "cow", "giraffe", "gorilla", "shark", "moose", "penguin"};

for(int k = 0; k <= 20; k++) {
l.insertNode(animals[k]);
}

cout << "This is the Default Linked List " << endl;
l.printList();

cout << endl;

cout << "This is the list of animals with the letter r." << endl;
l.printListEX(r);

cout << endl;

l.deleteNode(12);
l.deleteNodeC(o);
 
cout << "This is the Linked List after deleting the 12th Node and any animal with letter o." << endl;
l.printList();

cout << endl;

l.insertNodePos("Whale", 6);

cout << "This is the linked list after inserting Whale." << endl;
l.printList();

return 0;

} 
