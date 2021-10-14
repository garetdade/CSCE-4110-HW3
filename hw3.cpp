#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Global Variables
int size = 1000;

class Node{
public:
  int data = -1;
  Node *left, *right;
};


// Prototypes 
void numberGenerator(Node *arr[10]);
void printLinkedList(Node *arr[10]);


int main(){
// Declaring Variables
Node *arr[10];
int i, j;

// Initalizing all the nodes in the array of pointers.
for (i = 0; i < 10; i++){
  arr[i] = new Node();
}

// Calling number generator
numberGenerator(arr);

// Printing out Linked Lists
printLinkedList(arr);



  return 0;
}


void numberGenerator(Node *arr[10]){
  // Initialzing the seed
  srand(time(NULL));

  // Generating a temporary Node
  Node *last;
  Node *newNode;

  // Looping through array and generating 10xsize numbers
  for (int j = 0; j < 10; j++){
    for (int i = 0; i < size; i++){
      if (arr[j]->left == NULL && arr[j]->data == -1){
        // populate the first node if it is empty, assign to last
        arr[j]->data = rand() % 1000;
        last = arr[j];
      }
      else{
        // Creaet new node and popuate it
        newNode = new Node();
        newNode->data = rand() % 1000;
        newNode->left = last;

        // attach it to end of linked list and set last to the end of the list
        last->right = newNode;
        last = newNode;
      }
    }
  }
}

void printLinkedList(Node *arr[10]){
  // Printing out the contents of the arrays
  Node *temp = new Node();
  for (int i = 0; i < 10; i++){
    cout << "Printing out list #" << i+1 << endl << endl;
    temp = arr[i];
    for (int j = 0; j < size; j++){
      cout << temp->data << " ";
      temp = temp->right;
      if ( j%10 == 0 && j != 0){
        cout << endl;
      }
    }
    cout << endl << endl;
  }
}
