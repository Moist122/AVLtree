#include "BST.hh"
template <typename Position>
Node<Position>* SearchTree<Position>::remove(Node<Position>* n) {
    if(n->left()->isExternal()) return this->removeAboveExternal(n->left());
    else if(n->right()->isExternal()) return this->removeAboveExternal(n->right());
    else {
        Node<Position>* substitute=n->right();
        while(!substitute->left()->isExternal())
            substitute=substitute->left();
        **n=**substitute;
        return this->removeAboveExternal(substitute->left());
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
Node<Position>* SearchTree<Position>::find(Position value, Node<Position>* n) {
    Node<Position>* current=n;
    while((!current->isExternal())&&**current!=value) {
        if(**current<value) current=current->right();
        else current=current->left();
    }
    return current;
}
template <typename Position>
List<Position> SearchTree<Position>::findAll(Position value) {
    List<Position> l;
    List<Position> toCheck;
    toCheck.append(&(this->root()));
    while(!toCheck.empty()) {
        Node<Position>* toAdd=find(value,toCheck.pop());
        if(!toAdd->isExternal()){
            l.append(toAdd);
            toCheck.append(toAdd->left());
            toCheck.append(toAdd->right());
        }
    }
    return l;
}