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
    //cout<<t.size()<<endl;
    for(int i=0;i<20;++i) t.insert(rand()%2001-1000);
    t.insert(1);
    t.insert(15);
    cout<<endl<<endl<<endl;
    t.insert(1);
    cout<<"ok"<<endl;
    eulerianTour(&t);
    cout<<endl<<endl;
    for(int i=0;i<3;++i) t.remove(t.root().right());
    t.remove(&t.root());
    eulerianTour(&t);
    cout<<endl<<endl;
    List<int> l=t.entries();
    Element<int>* current=l.head();
    while(current!=nullptr) {
        cout<<****current<<endl;
        current=current->next();
    }
    cout<<endl<<endl;
    //Node<int>* f=t.find(15, &t.root());
    List<int> l2=t.findAll(1);
    current=l2.head();
    while(current!=nullptr) {
        cout<<****current<<endl;
        current=current->next();
    }
}