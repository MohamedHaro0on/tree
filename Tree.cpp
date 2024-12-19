#ifndef TREE_CPP
#define TREE_CPP
#include "Tree.h"

template <class T>
Node<T> *Tree<T>::getNodeByData(T data)
{
    Node<T> *current = root;
    while (current != nullptr)
    {
        if (data == current->data)
        {
            return current;
        }
        else if (data > current->data)
        {
            current = current->Right;
        }
        else
        {
            current = current->Left;
        }
    }
    return nullptr;
}

template <class T>
Node<T> *Tree<T>::getParent(Node<T> *node)
{
    Node<T> *parent = root;
    while (parent != nullptr)
    {
        if (parent->Left == node || parent->Right == node)
        {
            return parent;
        }
        else if (node->data > parent->data)
        {
            parent = parent->Right;
        }
        else
        {
            parent = parent->Left;
        }
    }
    return nullptr;
}

template <class T>
Node<T> *Tree<T>::getMaxRight(Node<T> *node)
{
    Node<T> *current = node;
    while (current->Right != nullptr)
    {
        current = current->Right;
    }
    return current;
}

template <class T>
Node<T> *Tree<T>::getMaxLeft(Node<T> *node)
{
    Node<T> *current = node;
    while (current->Left != nullptr)
    {
        current = current->Left;
    }
    return current;
}

// Function to do inorder traversal of BST

template <class T>
void Tree<T>::display(Node<T> *root)
{
    if (root != nullptr)
    {
        display(root->Left);
        cout << root->data << " ";
        display(root->Right);
    }
}

template <class T>
Node<T> *Tree<T>::minNode(Node<T> *root)
{

    return getMaxLeft(root);
}

template <class T>
Node<T> *Tree<T>::maxNode(Node<T> *root)
{

    return getMaxRight(root);
}

template <class T>
Tree<T>::Tree()
{
    root = nullptr;
}

template <class T>
void Tree<T>::add(T _data)
{
    Node<T> *newNode = new Node<T>(_data);
    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        Node<T> *current = root;
        Node<T> *parent = root;
        while (current != nullptr)
        {
            parent = current;
            if (_data > current->data)
            {
                current = current->Right;
            }
            else
            {
                current = current->Left;
            }
        }
        if (_data > parent->data)
        {
            parent->Right = newNode;
        }
        else
        {
            parent->Left = newNode;
        }
    }
}

template <class T>
T Tree<T>::getParentBydata(T data)
{
    Node<T> *node = getNodeByData(data);
    if (node == root)
    {
        throw "ROOT Not Have Parent";
    }
    if (node != nullptr)
    {
        Node<T> *res = getParent(node);
        if (res != nullptr)
        {
            return res->data;
        }
    }
    throw "Not Found";
}

/// Function to delete a node

template <class T>
void Tree<T>::deleteNode(T _data)
{

    if (root == nullptr)
        return;
    Node<T> *node = getNodeByData(_data);
    if (node == nullptr)
        return;
    if (node == root)
    {
        if (node->Left == nullptr && node->Right == nullptr)
            root = nullptr;
        else
        {
            // node with only one child
            if (root->Left == nullptr)
            {
                root = root->Right;
            }
            else if (root->Right == nullptr)
            {
                root = root->Left;
            }
            else
            {
                // node with two children:
                Node<T> *FLNode = node->Left;
                Node<T> *MRNode = getMaxRight(FLNode);
                MRNode->Right = node->Right;
                // node -->> root
                root = node->Left;
            }
        }
    }
    else
    {
        Node<T> *parent = getParent(node);
        Node<T> *child;
        if (node->Left == nullptr && node->Right == nullptr)
        {
            child = nullptr;
        }
        else if (node->Right == nullptr)
        {
            child = node->Left;
        }
        else if (node->Left == nullptr)
        {
            child = node->Right;
        }
        else
        {
            // node with two children:
            Node<T> *FLNode = node->Left;
            Node<T> *MRNode = getMaxRight(FLNode);
            MRNode->Right = node->Right;
            child = node->Left;
        }
        if (parent->Left == node)
        {
            parent->Left = child;
        }
        else if (parent->Right == node)
        {
            parent->Right = child;
        }
    }
    delete node;
}

template <class T>
void Tree<T>::displayAll()
{
    display(root);
}

template <class T>
T Tree<T>::minNode()
{
    Node<T> *node = minNode(root);
    return node->data;
}

template <class T>
T Tree<T>::maxNode()
{
    Node<T> *node = maxNode(root);
    return node->data;
}

template <class T>
Tree<T>::~Tree()
{
}

template class Tree<int>;
template class Tree<double>;

#endif // TREE_H