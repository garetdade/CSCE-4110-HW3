#include <iostream>

using namespace std;

struct node {
    int data = -1;
    node* left;
    node* right;
    node* parent;
    string color;
    int rotationCount = 0;
};
