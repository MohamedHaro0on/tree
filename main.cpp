#include "Tree.h"
#include <iostream>

int main()
{
    // Create a Tree of integers
    Tree<int> intTree;

    // Add some elements to the tree
    intTree.add(10);
    intTree.add(5);
    intTree.add(15);
    intTree.add(3);
    intTree.add(7);
    intTree.add(12);
    intTree.add(18);

    // Display all elements in the tree
    std::cout << "Tree elements in order:" << std::endl;
    intTree.displayAll();
    std::cout << std::endl;

    std::cout << "Minimum element: " << intTree.minNode() << std::endl;
    std::cout << "Maximum element: " << intTree.maxNode() << std::endl;

    try
    {
        int data = 7;
        std::cout << "Parent of " << data << ": " << intTree.getParentBydata(data) << std::endl;
    }
    catch (const char *msg)
    {
        std::cerr << msg << std::endl;
    }

    intTree.deleteNode(10);
    std::cout << "Tree elements after deleting 10:" << std::endl;
    intTree.displayAll();
    std::cout << std::endl;

    return 0;
}