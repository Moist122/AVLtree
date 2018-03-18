#include "AVLtree.hh"
#include<iostream>
template<typename Position>
void preorderTraversal(SearchTree<Position>* T, Node<Position>* p) {
    std::cout<<**p<<std::endl;
    if(!p->left()->isExternal()) preorderTraversal(T, p->left());
    if(!p->right()->isExternal()) preorderTraversal(T, p->right());
}
template<typename Position>
void preorderTraversal(SearchTree<Position>* T) {
    preorderTraversal(T, &(T->root()));
}
template<typename Position>
void postorderTraversal(SearchTree<Position>* T, Node<Position>* p) {
    if(!p->left()->isExternal()) postorderTraversal(T, p->left());
    if(!p->right()->isExternal()) postorderTraversal(T, p->right());
    std::cout<<**p<<std::endl;
}
template<typename Position>
void postorderTraversal(SearchTree<Position>* T) {
    postorderTraversal(T, &(T->root()));
}
template<typename Position>
void inorderTraversal(SearchTree<Position>* T, Node<Position>* p) {
    if(!p->left()->isExternal()) inorderTraversal(T, p->left());
    std::cout<<**p<<std::endl;
    if(!p->right()->isExternal()) inorderTraversal(T, p->right());
}
template<typename Position>
void inorderTraversal(SearchTree<Position>* T) {
    inorderTraversal(T, &(T->root()));
}

/*void eulerianTour(SearchTree *T) {

}
*/
/*
int depth(Position* p) {
    int d=0;
    while(p->getParent()!=nullptr) {
        p=p->getParent();
        d++;
    }
    return d;
}

void printArray(int array[][3], int counter){
    //sortArray(array,counter);

}

void printTree(SearchTree* T, Position* p, int positions[][3], int* counter) {
    if(p->getLeft()!=nullptr) inorderTraversal(T, p->getLeft());
    positions[*counter,depth(p),**p];
    (*counter)++;
    if(p->getRight()!=nullptr) inorderTraversal(T, p->getRight());
    if(*counter==T->getSize()-1){
        printArray(positions, *counter);
        delete counter;
    }
}

void printTree(SearchTree* T) {
    int positions [T->getSize()][3]; //[x,y,value]
    int *counter = new int(0);
    printTree(T, T->getRoot(), positions, counter);
}*/