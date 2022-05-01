/*
   Name: Edwin Soto-Villela
   Email: Edwinsoto-villela@my.unt.edu
   EUID: ejs0188
   Class: CSCE 3110
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <algorithm>
using namespace std;

/******************************* NODE START ****************************/
class Node
{
    double data;
    Node *left;
    Node *right;

public:
    // Default Constructor
    Node();

    // Parameterized Constructor
    Node(double);

    // Functions
    bool insertNode(Node *root, Node n);
    Node *search(Node *root, double data);
    void printNodes(Node *root);
};

// Default Constructor
Node::Node() : data(0), left(NULL), right(NULL) {}

// Parameterized Constructor
Node::Node(double value)
{
    data = value;
    this->left = NULL;
    this->right = NULL;
}

/*
 INSERT FUNCTION:
 Compares current parent node value < insert node value
    ->If the current left parent node is empty, then assign left node to new inserted node
    ->Recursively insert, new parent node is now current parent's left node
 Compares current parent node value > insert node value
    ->If the current right parent node is empty, then assign right node to new inserted node
    ->Recursively insert, new parent node is now current parent's right node
*/
bool Node::insertNode(Node *parent, Node n)
{
    if (n.data < parent->data)
    {

        if (parent->left == NULL)
        {
            parent->left = &n;
            return true;
        }
        else
        {
            insertNode(parent->left, n);
        }
    }
    else if (n.data > parent->data)
    {

        if (parent->right == NULL)
        {
            parent->right = &n;
            return true;
        }
        else
        {
            insertNode(parent->right, n);
        }
    }
    return false;
}

/*
 SEARCH FUNCTION:
 if the value is the same as the parent, then return the parent itself
 else,
    compare the parent to the value that I'm searching for
    ->if the value is less than parent, move left on the tree
    ->if the value is more than the parent, move right on the tree
*/
Node *Node::search(Node *parent, double value)
{
    if (parent->data == value)
    {
        return parent;
    }
    else
    {
        if (parent->data > value)
        {
            if (parent->left == NULL)
            {
                return NULL;
            }
            else
            {
                search(parent->left, value);
            }
        }
        else if (parent->data < value)
        {
            if (parent->right == NULL)
            {
                return NULL;
            }
            else
            {
                search(parent->right, value);
            }
        }
    }
}

/*
    PRINT FUCNTION:
    This function is to take in the root node and output the children
    and leafs of the Binary Search Tree
*/
void Node::printNodes(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    printNodes(root->left);
    cout << root->data << " ";
    printNodes(root->right);
}
/************************************** NODE END ************************************/

/************************************ TREE START ************************************/
class Tree
{
public:
    int nodes;
    int treeDepth;
    Node root;

    int size();
    int depth();
    bool insert(Node *root, double value);
    Node search(Node *root, double value);
};

/*  SIZE FUNCTION:
    This function is to return the numberof items inside the tree */
int Tree::size()
{
    return this->nodes;
}

/*  DEPTH FUNCTION:
    This function is to return the depth of the tree */
int Tree::depth()
{
    return this->treeDepth;
}

/* Tree Insert Function:
   Insert the root and the value into the tree
   If the root node is empty, set the node  to the root
   Else, insert the node into the tree  */
bool Tree::insert(Node *root, double value)
{
    Node n = Node(value);
    if (root == NULL)
    {
        root = &n;
        return true;
    }
    return root->insertNode(root, n);
}

/*
    Tree Search Function:
    Search for the given root and value from the tree
    If the root is empty, then return an empty tree
    Else, search the value in the tree
*/
Node Tree::search(Node *root, double value)
{
    if (root == NULL)
    {
        return NULL;
    }
    return *root->search(root, value);
}
/************************************ TREE END ***********************************/

/*
    TESTER FUNTION:
    This function is suppsoe to test out automatic generated values and
    input those values into the Binary Search Tree Function
*/
void valueTester(int size, bool sortNum = false)
{
    srand(time(0)); // Random generator
    Tree tree = Tree();
    double values[size];
    int dupCount = 0;  // Duplication Count
    Node *root = NULL; // Initializing an empty node

    for (int i = 0; i < size; i++)
    {
        values[i] = rand() % size;
    }
    if (sortNum)
        sort(values, values + size);
    auto time1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        if (!tree.insert(root, values[i]))
        {
            dupCount++;
        }
    }
    auto time2 = std::chrono::high_resolution_clock::now();
    cout << "Time to insert: " << chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count() << " us" << endl;
    cout << "function Duplicate{insert failed}: " << dupCount << endl;
    cout << "___________________________________________________\n\n";

    time1 = std::chrono::high_resolution_clock::now();
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        found++;
    }
    time2 = std::chrono::high_resolution_clock::now();
    cout << "Search Time: " << std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count() << " us" << endl;
    cout << found << " elements out of " << size << " elements \n______________________________________________\n\n";

    time1 = std::chrono::high_resolution_clock::now();
    cout << "Size: " << tree.size() << endl;
    time2 = std::chrono::high_resolution_clock::now();
    cout << "Size Time: " << std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count() << " us \n_______________________________________\n\n";

    time1 = std::chrono::high_resolution_clock::now();
    cout << "Depth: " << tree.depth() << endl;
    time2 = std::chrono::high_resolution_clock::now();
    cout << "Time to reach depth: " << std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count() << " us \n_____________________________________\n\n";
}

int main()
{
    Node *root = NULL; // Initializing an empty node
    Tree tree = Tree();
    Node n = Node();
    double choice;

    bool inserted = tree.insert(root, 5.0); // Inserts

    if (inserted)
    {
        cout << "The value has been inserted" << endl;
    }

    cout << "Enter a value you want to search: ";
    cin >> choice;

    tree.search(root, choice); // Searches for value
    n.printNodes(root);        // Prints out the tree

    // Test random generated values without sorting
    cout << "Values without sorting" << endl;
    valueTester(100);
    valueTester(1000);
    valueTester(10000);

    // Test random generated values with BST
    cout << "Values with BST" << endl;
    valueTester(100, true);
    valueTester(1000, true);
    valueTester(10000, true);

    return 0;
}