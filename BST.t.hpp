#include "BST.hh"
template <typename Position>
Node<Position>* SearchTree<Position>::remove(Node<Position>* n) {
    if(n->getLeft()->isExernal()) return removeAboveExternal(n->getLeft());
    else if(n->getRight()->isExernal()) return removeAboveExternal(n->getRight());
    else {
        Position* substitute=n->right();
        while(!substitute->getLeft()->isExernal())
            substitute=substitute->getLeft();
        *n=*substitute;
        return removeAboveExternal(substitute->getLeft());
    }
}
template <typename Position>
Node<Position>* SearchTree<Position>::insert(Position v) {
        Node<Position>* toInsert=this->_root;
        while(!toInsert->isExternal()){
            if(**toInsert<v) toInsert=toInsert->right();
            else toInsert=toInsert->left();
        }
        toInsert->addValue(v);
        this->expandExternal(toInsert);
        return toInsert;
}
template <typename Position>
Node<Position>& SearchTree<Position>::find(Position value, Node<Position>* n) {
    Node<Position>* current=n;
    while((!current->isExternal())&&**current!=value) {
        if(**current<value) current=current->right();
        else current=current->left();
    }
    return *current;
}
template <typename Position>
List<Node<Position> > SearchTree<Position>::findAll(Position value) {
    List<Node<Position> > l;
    List<Node<Position> > toCheck;
    toCheck.append(this->root());
    while(!toCheck.empty()) {
        Position toAdd=find(value,toCheck.pop());
        if(!toAdd.isExternal()){
            l.append(toAdd);
            toCheck.append(toAdd.left());
            toCheck.append(toAdd.right());
        }
    }
    return l;
}