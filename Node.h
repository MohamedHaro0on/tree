#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
public:
    Node *Right;
    Node *Left;
    T data;
    Node(T _data)
    {
        data = _data;
        Right = Left = nullptr;
    }
    ~Node() {}
};

#endif // NODE_H
