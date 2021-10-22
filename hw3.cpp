#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Node.cpp"
#include "BST.cpp"
#include "RBT.cpp"

using namespace std;

//Global Variables
int size = 1000;


// Prototypes
void numberGenerator(node *arr[10]);
void printLinkedList(node *arr[10]);
void buildBST(node *arr[10], BST *bst[10]);
void buildRBT(node *arr[10], RB_TREE *rbt[10]);



int main(){
// Declaring Variables
node *arr[10];
BST *bst[10];
RB_TREE *rbt[10];
int i, j, ave;
int counter[10];

// Initalizing all the nodes in the array of pointers.
for (i = 0; i < 10; i++){
  arr[i] = new node();
  bst[i] = new BST();
  rbt[i] = new RB_TREE();
}

// Calling number generator
numberGenerator(arr);

// Printing out Linked Lists
printLinkedList(arr);

// Building BST
buildBST(arr, bst);

// printing ordered BST
cout << "\n\n Printing out BST\n\n";
for (i = 0; i < 10; i++){
  cout << "\n Printing case " << i+1 << endl << endl;
  bst[i]->display();
}

// Building Red Black Tree
buildRBT(arr, rbt);

/*// printing ordered RBT Preorder
cout << "\n\n Printing out Red Black Tree (Preorder)\n\n";
for (i = 0; i < 10; i++){
  cout << "\n Printing case " << i+1 << endl << endl;
  rbt[i]->PreorderTraversal(rbt[i]->GetRoot());
  cout << endl;
} */

// printing ordered RBT Inorder
cout << "\n\n Printing out Red Black Tree (Inorder)\n\n";
ave = 0;
for (i = 0; i < 10; i++){
  counter[i] = rbt[i]->averageRotation();
  ave += counter[i];
  cout << "\n Printing case " << i+1 << " -- Rotation Count: " << counter[i] << endl << endl;
  rbt[i]->display();
  cout << endl;
}
cout << "Average Roataion Count = " << ave/10 << "\n\n";

/*// printing ordered RBT Postorder
cout << "\n\n Printing out Red Black Tree (Postorder)\n\n";
for (i = 0; i < 10; i++){
  cout << "\n Printing case " << i+1 << endl << endl;
  rbt[i]->PostorderTraversal(rbt[i]->GetRoot());
  cout << endl;
} */

  return 0;
}





void numberGenerator(node *arr[10]){
  // Initialzing the seed
  srand(time(NULL));

  // Generating a temporary node
  node *last;
  node *newNode;

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
        newNode = new node();
        newNode->data = rand() % 1000;
        newNode->left = last;

        // attach it to end of linked list and set last to the end of the list
        last->right = newNode;
        last = newNode;
      }
    }
  }
}

void printLinkedList(node *arr[10]){
  // Printing out the contents of the arrays
  node *temp = new node();
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


void buildBST(node *arr[10], BST *bst[10]){
  // Building the BST off of the generated random numbers
  node *tempArr;
  for (int i = 0; i < 10; i++){
    tempArr = arr[i];
    for (int j = 0; j < size; j++){
      bst[i]->insert(tempArr->data);
      tempArr = tempArr->right;
    }
  }
}


void buildRBT(node *arr[10], RB_TREE *rbt[10]){
  // Building the Red Black Tree off of the generated numbers
  node *tempArr;
  for(int i = 0; i < 10; i++){
    tempArr = arr[i];
    for (int j = 0; j < size; j++){
      rbt[i]->InsertNode(tempArr->data);
      tempArr = tempArr->right;
    }
  }
}
