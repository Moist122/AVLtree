#pragma once
#include "BST.hh"
#include<cmath>

template <typename Position>
class AVLtree: public SearchTree<Position> {
public:
    void insert(Position pos) {makeBalanced(SearchTree<Position>::insert(pos));}
    void remove(Node<Position>* pos)
        {makeBalanced(SearchTree<Position>::remove(pos));}
    bool isBalanced(Node<Position>* n) const
        {return abs((n->left()->height())-(n->right()->height()))<2;}
protected:
    void makeBalanced(Node<Position>* n);
    Node<Position>* trinodeRestructuring(Node<Position>* x);
};