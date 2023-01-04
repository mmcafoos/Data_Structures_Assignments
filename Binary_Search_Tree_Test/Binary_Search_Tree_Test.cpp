/*
 * Implement the min() and nodeCount() method for the BST shown below.
 * min() returns the min key in the BST
 * nodeCount() returns the count of the nodes in the BST
 * Your implementation can either be iterative or recursive.
 * Do NOT modify the test.
 * Do NOT add any additional STLs
 * You can add private data, and methods to the BST if needed
 * Useful link for std::pair https://cplusplus.com/reference/utility/pair/pair/
 */
 
 
//Please note I added a helper the best way I could figure out as we 
//were given permission mid exam. If I did it in a way 
//I was not suppose to modify the code for, I do apologize
//Did not modify the test itself
#include <iostream>
#include <string>
#include <utility>
class Node
{
private:
    int key;
    std::string val;
    Node *left;
    Node *right;
    friend class BinarySearchTree;
};
class BinarySearchTree
{
public:
    BinarySearchTree() : root{nullptr}{}
    void insert(int key, std::string val); // Recursive
    std::pair<int, std::string> min();     // Returns the min key, and associated value
    int nodeCount(); // Returns the number of nodes
private:
    Node *root;
    void insertHelper(Node *parent, Node *new_node);
    std::pair<int, std::string> minHelp(Node *node); // recursive function that returns min key
    //I suppose I could've tried a max helper coming rrom the right, but I'm pretty sure that
    //violates the assignment 
    int nodeCountHelp(Node *node);                   // recursive function that calculates node number
};

void BinarySearchTree::insert(int key, std::string val)//No touching code here
{
    Node *new_node = new Node;
    new_node->key = key;
    new_node->val = val;
    new_node->left = nullptr;
    new_node->right = nullptr;
    if (root == nullptr)
    {
        root = new_node;
    }
    else
    {
        insertHelper(root, new_node);
    }
}

void BinarySearchTree::insertHelper(Node *parent, Node *new_node)//No touching code here
{
    if (new_node->key < parent->key){
        if (parent->left == nullptr){
            parent->left = new_node;
        }
        else{
            insertHelper(parent->left, new_node);
        }
    } 
    else if (new_node->key > parent->key) {
        if (parent->right == nullptr){
            parent->right = new_node;
        }
        else{
            insertHelper(parent->right, new_node);
        }
    }
}

std::pair<int,std::string>BinarySearchTree::min()
{
    return minHelp(root); 
    //I'm gonna be completely honest, I have no idea how To solve this without a helper
}
// leftmost node in BST typically has the smallest value
std::pair<int, std::string> BinarySearchTree::minHelp(Node *node)
{
    if (node->left)
        return minHelp(node->left); // if possible, go left
        //Once again, this is heavily based on the fact that we are required to use min
        //If given a choice, we could've gone from the right instead
    else
        return std::pair<int, std::string>(node->key, node->val); 
        // if not you have reached smallest node
}

// Hint: Traverse the tree and count the nodes
int BinarySearchTree::nodeCount()
{
    // Your code here
    return nodeCountHelp(root); 
}
int BinarySearchTree::nodeCountHelp(Node *node)
{
    if (node == nullptr)
        return 0; // typical nullptr stuff here
    if (node->right == nullptr && node->left == nullptr)
        return 1;                                       
    return 1 + nodeCountHelp(node->right) + nodeCountHelp(node->left); 
    // adds 1 to nodes in left and right subtrees
}

// Test
// Definitely no modified code here 
int main()
{
    BinarySearchTree t;
    t.insert(5, "Boron");
    t.insert(3, "Lithium");
    t.insert(7, "Nitrogen");
    t.insert(2, "Helium");
    t.insert(4, "Berylium");
    t.insert(6, "Carbon");
    t.insert(8, "Oxygen");
    auto minPair = t.min();
    std::cout << "Min key and value: " << minPair.first << " " << minPair.second << std::endl;
    std::cout << "Number of nodes: " << t.nodeCount() << std::endl;

    return 0;
}
