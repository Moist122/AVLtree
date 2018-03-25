#pragma once
#include "BST.hh"
#include<cmath>

template <typename Position>
//Binary search tree that balances itself
class AVLtree: public SearchTree<Position> {
public:
    int insert(Position pos) 
        {return makeBalanced(SearchTree<Position>::insert(pos), 0);}
        //insert pos, then rebalance tree
        //returns number of rotations
    int remove(Node<Position>* pos)
        {return makeBalanced(SearchTree<Position>::remove(pos), 0);}
        //remove pos, then rebalance tree
        //returns number of rotations
    bool isBalanced(Node<Position>* n) const
        {return abs((n->left()->height())-(n->right()->height()))<2;}
        //check if node n is balanced
protected:
    int makeBalanced(Node<Position>* n, int num);
        //check balance of node n then use restructuring if needed
        //returns number of rotations
    Node<Position>* trinodeRestructuring(Node<Position>* x);
        //algorithm restoring balance to node x, its parent and grandparent
};