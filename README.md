# Binary Search Tree Implementation

This project implements a generic Binary Search Tree (BST) in C++ using templates. The project contains the following key components:

### Files
- **Node.h**: Defines the `Node` class used to represent individual nodes in the BST.
- **Tree.h**: Declares the `Tree` class and its public and private member functions.
- **Tree.cpp**: Implements the `Tree` class member functions.
- **main.cpp**: Contains a test program demonstrating the usage of the `Tree` class.

---

## Node Class

The `Node` class is a templated class used to represent a node in the BST. It contains the following attributes:
- `T data`: The data stored in the node.
- `Node *Right`: Pointer to the right child node.
- `Node *Left`: Pointer to the left child node.

### Constructor:
```cpp
Node(T _data)
```
Initializes the node with the given data and sets its child pointers to `nullptr`.

---

## Tree Class

The `Tree` class is a templated class that represents the Binary Search Tree. It provides functionality to add, remove, and query nodes.

### Key Member Functions

#### Public Functions:
- `Tree()`: Constructor to initialize the tree.
- `void add(T _data)`: Adds a node with the given data to the tree.
- `void deleteNode(T _data)`: Deletes the node with the specified data from the tree.
- `void displayAll()`: Displays all the elements in the tree in in-order traversal.
- `T getParentBydata(T data)`: Retrieves the parent of the node containing the specified data.
- `T minNode()`: Returns the smallest element in the tree.
- `T maxNode()`: Returns the largest element in the tree.
- `~Tree()`: Destructor for the tree.

#### Private Functions:
- `Node<T> *getNodeByData(T data)`: Finds and returns a pointer to the node containing the specified data.
- `Node<T> *getParent(Node<T> *node)`: Finds and returns the parent of a given node.
- `Node<T> *getMaxRight(Node<T> *node)`: Finds the rightmost child of a subtree.
- `Node<T> *getMaxLeft(Node<T> *node)`: Finds the leftmost child of a subtree.
- `Node<T> *minNode(Node<T> *root)`: Finds the node with the smallest value in a subtree.
- `Node<T> *maxNode(Node<T> *root)`: Finds the node with the largest value in a subtree.
- `void display(Node<T> *root)`: Recursively performs an in-order traversal starting from the given root.

---

## main.cpp

This file demonstrates the usage of the `Tree` class with an example of a BST of integers.

### Operations Performed:
1. Creating a tree.
2. Adding elements (10, 5, 15, 3, 7, 12, 18).
3. Displaying all elements in in-order traversal.
4. Retrieving and displaying the minimum and maximum elements.
5. Retrieving the parent of a specified node (e.g., 7).
6. Deleting a node (e.g., 10).
7. Displaying the tree elements again after deletion.

### Example Output:
```plaintext
Tree elements in order:
3 5 7 10 12 15 18

Minimum element: 3
Maximum element: 18

Parent of 7: 5

Tree elements after deleting 10:
3 5 7 12 15 18
```

---

## Usage

### Compiling the Program
Use the following command to compile the program:
```bash
g++ -o tree main.cpp
```

### Running the Program
Run the compiled program:
```bash
./tree
```

---

## Key Features
- **Generic Implementation**: The tree can store any data type supported by C++ templates (e.g., integers, doubles).
- **In-Order Traversal**: Displays the elements in sorted order.
- **Parent Retrieval**: Efficiently retrieves the parent of a specified node.
- **Deletion**: Handles node deletion for leaf nodes, nodes with one child, and nodes with two children.

---

## Limitations
- The current implementation does not support balancing. For large datasets, the tree may become unbalanced, resulting in degraded performance.
- Exceptions are thrown as C-style strings. Future enhancements can include better exception handling using `std::exception` or custom exceptions.

---

## Future Improvements
- Add support for balancing algorithms (e.g., AVL tree, Red-Black tree).
- Implement more robust exception handling.
- Extend the functionality to include pre-order and post-order traversals.

---

## Author
[Mohamed Ahmed Ali Haroon]

