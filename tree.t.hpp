#include "tree.hh"

template <typename Position>
void BinaryTree<Position>::deleteRecursively(Node<Position>* n) {
    if(!n->isExternal()) {
        deleteRecursively(n->left());
        deleteRecursively(n->right());
    }
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
    if(!n->left()->isExternal()) appendToListRecursively(n->left(), l);
    if(!n->right()->isExternal()) appendToListRecursively(n->right(), l);
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
    if(n->isExternal()){
        Node<Position>* toDelete=n->parent();
        Node<Position>* toSave;
        if(toDelete->left()==n) toSave=toDelete->right();
        else toSave=toDelete->left();
        Node<Position>* grandparent=toDelete->parent();
        toSave->setParent(grandparent);
        if(grandparent->left()==toDelete) grandparent->setLeft(toSave);
        else grandparent->setRight(toSave);
        delete n;
        delete toDelete;
        _size-=2;
        return grandparent;
    }
}