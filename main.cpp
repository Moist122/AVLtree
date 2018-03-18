#include<iostream>
#include "AVLtree.hh"
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
    //for(int i=0;i<3;++i) t.insert(rand()%2001-1000);
    t.insert(44);
    t.insert(17);
    t.insert(62);
    t.insert(32);
    t.insert(50);
    t.insert(78);
    t.insert(48);
    t.insert(54);
    t.insert(88);
    preorderTraversal(&t);
    cout<<endl;
    postorderTraversal(&t);
    cout<<endl;
    inorderTraversal(&t);
    cout<<endl;
    t.remove(t.root().left()->right());
    List<int> l=t.entries();
    Element<int>* current=l.head();
    cout<<endl;
    while(current!=nullptr) {
        cout<<**current<<endl;
        current=current->next();
    }
}