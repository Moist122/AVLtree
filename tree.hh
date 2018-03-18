#pragma once
#include "node.hh"
#include "list.hh"
template <typename Position>
//Any binary tree
class BinaryTree {
public:
    BinaryTree()
        :_root(nullptr), _size(0) {}
    ~BinaryTree() {deleteRecursively(_root);}

    bool isEmpty() const {return _size==0;}
        //is tree empty?
    int size() const {return _size;}
        //number of nodes including external
    List<Position> entries();
        //preorder traversal adding Nodes to list
    void addRoot() {_root=new Node<Position>; _size=1;}
        //add root node to empty tree
    void setRoot(Node<Position>* n) {_root=n;}
        //set value of root node to n
    Node<Position>& root() {return *_root;}
        //get root
    void deleteRecursively(Node<Position>* n);
        //delete n and every node below it

protected:
    void expandExternal(Node<Position>* n);
    Node<Position>* removeAboveExternal(Node<Position>* n);
    void appendToListRecursively(Node<Position>* n, List<Position>& l);

protected:
    Node<Position>* _root;
    int _size;
};