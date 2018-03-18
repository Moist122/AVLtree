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
    preorderTraversal(T, T->root());
}
template<typename Position>
void postorderTraversal(SearchTree<Position>* T, Node<Position>* p) {
    if(!p->left()->isExternal()) postorderTraversal(T, p->left());
    if(!p->right()->isExternal()) postorderTraversal(T, p->right());
    std::cout<<**p<<std::endl;
}
template<typename Position>
void postorderTraversal(SearchTree<Position>* T) {
    postorderTraversal(T, T->root());
}
template<typename Position>
void inorderTraversal(SearchTree<Position>* T, Node<Position>* p) {
    if(!p->left()->isExternal()) inorderTraversal(T, p->left());
    std::cout<<**p<<std::endl;
    if(!p->right()->isExternal()) inorderTraversal(T, p->right());
}
template<typename Position>
void inorderTraversal(SearchTree<Position>* T) {
    inorderTraversal(T, T->root());
}
template<typename Position>
void eulerianTour(SearchTree<Position>* T, Node<Position>* p) {
    std::cout<<"Left:"<<**p<<std::endl;
    if(!p->left()->isExternal()) eulerianTour(T, p->left());
    std::cout<<"Down:"<<**p<<std::endl;
    if(!p->right()->isExternal()) eulerianTour(T, p->right());
    std::cout<<"Right:"<<**p<<std::endl;
}
template<typename Position>
void eulerianTour(SearchTree<Position>* T) {
    eulerianTour(T, T->root());
}