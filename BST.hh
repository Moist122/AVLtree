#pragma once
#include "tree.hh"

template <typename Position>
//binary search tree
class SearchTree : public BinaryTree<Position> {
public:
    Node<Position>* insert(Position v);
        //insert node with position v
    Node<Position>* remove(Node<Position>* n);
        //remove node n from tree
    Node<Position>* find(Position value, Node<Position>* n);
        //find 1 node with position value
    List<Position> findAll(Position value);
        //find all nodes with positions value
protected:
    void findAll(Position value, List<Node<Position> >* l);
};