#pragma once
#include "BST.hh"
#include<cmath>

template <typename Position>
//Binary search tree that balances itself
class AVLtree: public SearchTree<Position> {
public:
    void insert(Position pos) {makeBalanced(SearchTree<Position>::insert(pos));}
        //insert pos, then rebalance tree
    void remove(Node<Position>* pos)
        {makeBalanced(SearchTree<Position>::remove(pos));}
        //remove pos, then rebalance tree
    bool isBalanced(Node<Position>* n) const
        {return abs((n->left()->height())-(n->right()->height()))<2;}
        //check if node n is balanced
protected:
    void makeBalanced(Node<Position>* n);
    Node<Position>* trinodeRestructuring(Node<Position>* x);
};