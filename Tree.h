#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <iostream>
using std::cout;
using std::endl;
template <class T>
class Tree
{
private:
    Node<T> *root;
    Node<T> *getNodeByData(T data);

    Node<T> *getParent(Node<T> *node);

    Node<T> *getMaxRight(Node<T> *node);
    Node<T> *getMaxLeft(Node<T> *node);

    // Function to do inorder traversal of BST
    void display(Node<T> *root);

    Node<T> *minNode(Node<T> *root);

    Node<T> *maxNode(Node<T> *root);

public:
    Tree();

    void add(T _data);

    T getParentBydata(T data);

    /// Function to delete a node
    void deleteNode(T _data);

    void displayAll();

    T minNode();

    T maxNode();

    ~Tree();
};

#endif // TREE_H