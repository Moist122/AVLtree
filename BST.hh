#pragma once
#include "tree.hh"

template <typename Position>
class SearchTree : public BinaryTree<Position> {
public:
    SearchTree()
        :BinaryTree<Position>() {}
    //~SearchTree() {}
    Node<Position>* insert(Position v);
    Node<Position>* remove(Node<Position>* n);
    Node<Position>* find(Position value, Node<Position>* n);
    List<Position> findAll(Position value);
protected:
    void findAll(Position value, List<Node<Position> >* l);
};