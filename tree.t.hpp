#include "tree.hh"

template <typename Position>
void BinaryTree<Position>::deleteRecursively(Node<Position>* n) {
    if(n->_left!=nullptr) deleteRecursively(n->_left);
    if(n->_right!=nullptr) deleteRecursively(n->_right);
    delete n;
}
template <typename Position>
List<Position> BinaryTree<Position>::entries() {
    List<Position> l;
    appendToListRecursively(_root, l);
    return l;
}
template <typename Position>
void BinaryTree<Position>::appendToListRecursively(Node<Position>* n, List<Position>& l) {
    l.append(n);
    if(!n->_left->isExternal()) appendToListRecursively(n->_left, l);
    if(!n->_right->isExternal()) appendToListRecursively(n->_right, l);
}
template <typename Position>
void BinaryTree<Position>::expandExternal(Node<Position>* n) {
    if(n->isExternal()){
        n->setLeft(new Node<Position>(n));
        n->setRight(new Node<Position>(n));
        _size+=2;
    }
}
template <typename Position>
Node<Position>* BinaryTree<Position>::removeAboveExternal(Node<Position>* n){
    if(n.isExernal()){
        Position* toDelete=n->parent();
        Position* toSave=
            toDelete->left()==&n ? toDelete->right() : toDelete->left();
        Position* grandparent=toDelete->parent();
        toSave->setParent(grandparent);
        if(&(grandparent->left())==toDelete) grandparent->setLeft(toSave);
        else grandparent->setRight(&toSave);
        delete n;
        delete toDelete;
        return grandparent;
    }
    size-=2;
}