#include "tree.hh"

template <typename Position>
void BinaryTree<Position>::deleteRecursively(Node<Position>* n) {
    if(!n->isExternal()) {
        deleteRecursively(n->_left);
        deleteRecursively(n->_right);
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
    std::cout<<"in rae"<<std::endl;
    if(n->isExternal()){
        Node<Position>* toDelete=n->parent();
        Node<Position>* toSave;
        if(toDelete->left()==n) toSave=toDelete->right();
        else toSave=toDelete->left();
        std::cout<<"all set"<<std::endl;
        Node<Position>* grandparent=toDelete->parent();
        toSave->setParent(grandparent);
        if(grandparent->left()==toDelete) grandparent->setLeft(toSave);
        else grandparent->setRight(toSave);
        std::cout<<"ready to delete"<<std::endl;
        delete n;
        std::cout<<"ok"<<std::endl;
        delete toDelete;
        std::cout<<"ok"<<std::endl;
        std::cout<<**grandparent<<std::endl;
        _size-=2;
        return grandparent;
    }
}