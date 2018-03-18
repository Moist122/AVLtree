#pragma once
#include "node.hh"
#include "list.hh"
template <typename Position>
class BinaryTree {
public:
    BinaryTree()
        :_root(nullptr), _size(0) {}
    ~BinaryTree() {/*deleteRecursively(_root);*/}

    bool isEmpty() const {return _size==0;}
    int size() const {return _size;}
    List<Position> entries(); //preorder
    void addRoot() {_root=new Node<Position>; _size=1;}
    void setRoot(Node<Position>* n) {_root=n;}
    Node<Position>& root() {return *_root;}
    void deleteRecursively(Node<Position>* n);

protected:
    void expandExternal(Node<Position>* n);
    Node<Position>* removeAboveExternal(Node<Position>* n);
    void appendToListRecursively(Node<Position>* n, List<Position>& l);

protected:
    Node<Position>* _root;
    int _size;
};