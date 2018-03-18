#include<iostream>
#include "BST.hh"
#include "node.t.hpp"
#include "list.t.hpp"
#include "tree.t.hpp"
#include "BST.t.hpp"
#include "AVLtree.t.hpp"
#include "traversals.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    AVLtree<int> t;
    t.addRoot();
    for(int i=0;i<10;++i) t.insert(rand()%2001-1000);
    preorderTraversal(&t);
    cout<<endl;
    postorderTraversal(&t);
    cout<<endl;
    inorderTraversal(&t);
    cout<<endl;
    List<int> l=t.entries();
    Element<int>* current=l.head();
    cout<<endl;
    while(current!=nullptr) {
        cout<<**current<<endl;
        current=current->next();
    }
}