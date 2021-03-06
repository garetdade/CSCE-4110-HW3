#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include "Node.cpp"
#include "RBT.cpp"
#include <chrono>
#include <iomanip>
using namespace std;

// Prototypes
void numberGenerator(node *arr[10], int);
void buildRBT(node *arr[10], RB_TREE *rbt[10], int);


int main() {
  // Declaring Variables
  int size = 1000;
  node *arr[size];
  RB_TREE *rbt[size];

// Initalizing all the nodes in the array of pointers.
  for (int i = 0; i < 1000; i++) {
    arr[i] = new node();
    rbt[i] = new RB_TREE();
  }

  cout << setw(10) << "N" << setw(20) << "TIME" << endl;
  for(int i = 0; i < 35; i++)
    cout << '*';
  cout << endl;

  for(int i = 100; i <= 1000; i += 100) {
    // Calling number generator
    numberGenerator(arr, i);

    auto start = chrono::high_resolution_clock::now();

    // Building Red Black Tree
    buildRBT(arr, rbt, i);

    auto end = chrono::high_resolution_clock::now();

    cout << setw(10) << i << setw(20)
        << (chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / 10
        << " ns\n";

    // resetting arr and rbt
    for (int j = 0; j < 1000; j++) {
      arr[j] = new node();
      rbt[j] = new RB_TREE();
    }
  }

  return 0;
}

// generates an array of 10 linked lists of random numbers
void numberGenerator(node *arr[10], int size) {
  // Initialzing the seed
  srand(time(NULL));

  // Generating a temporary node
  node *last;
  node *newNode;

  // Looping through array and generating 10xsize numbers
  for (int j = 0; j < 10; j++) {
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

// builds a RB Tree
void buildRBT(node *arr[10], RB_TREE *rbt[10], int size) {
  // Building the Red Black Tree off of the generated numbers
  node *tempArr;
  for(int i = 0; i < 10; i++) {
    tempArr = arr[i];

    for (int j = 0; j < size; j++) {
      rbt[i]->InsertNode(tempArr->data);
      tempArr = tempArr->right;
    }
  }
}
