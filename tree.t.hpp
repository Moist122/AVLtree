#include "tree.hh"

template <typename Position>
void BinaryTree<Position>::addRoot(){
    if(_root!=nullptr)
        throw TreeAlreadyRootedException("You can't add second root to this tree");
    _root=new Node<Position>;
    _size=1;
}
template <typename Position>
Node<Position>* BinaryTree<Position>::root() {
    if(_root==nullptr)
        throw UnrootedTreeException("That tree has no root");
    return _root;
}
template <typename Position>
void BinaryTree<Position>::deleteRecursively(Node<Position>* n) {
    if(_root==nullptr) return;
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
        if(_size==1) {
            delete n;
            _size-=1;
            return nullptr;
        }
        Node<Position>* toDelete=n->parent();
        Node<Position>* toSave;
        if(toDelete->left()==n) toSave=toDelete->right();
        else toSave=toDelete->left();
        Node<Position>* grandparent=toDelete->parent();
        toSave->setParent(grandparent);
        if(grandparent!=nullptr) {
            if(grandparent->left()==toDelete) grandparent->setLeft(toSave);
            else grandparent->setRight(toSave);
        }
        delete n;
        delete toDelete;
        _size-=2;
        if(_size<=3) {
            setRoot(toSave);
            return toSave;
        }
        return grandparent;
    }
}