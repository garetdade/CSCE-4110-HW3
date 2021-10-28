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
void numberGenerator(node *arr[10]);
void buildRBT(node *arr[10], RB_TREE *rbt[10]);


int main() {
  // Declaring Variables
  node *arr[10];
  RB_TREE *rbt[10];
  int size = 100;

// Initalizing all the nodes in the array of pointers.
  for (i = 0; i < 10; i++) {
    arr[i] = new node();
    rbt[i] = new RB_TREE();
  }

  cout << setw(10) << "N" << setw(10) << "TIME" << endl;
  for(int i; i < 22; i++)
    cout << *;
  cout << endl;

  for(;size < 1000; size += 100) {
    // Calling number generator
    numberGenerator(arr, size);

    auto start = chrono::steady_clock::now();

    // Building Red Black Tree
    buildRBT(arr, rbt, size);

    auto end = chrono::steady_clock::now();

    cout << setw(10) << size << setw(10)
        << (chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / 10
        << " ns\n";
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
