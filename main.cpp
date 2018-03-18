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

void menu() {
    cout<<endl<<"m - menu"<<endl
    <<"a - add nodes"<<endl
    <<"r - remove node"<<endl
    <<"t - test(20 random nodes)"<<endl
    <<"s - Eulerian tour"<<endl
    <<"e - exit"<<endl;
}
template <typename Position>
void test(AVLtree<Position>& t) {
    for(int i=0;i<20;++i) t.insert(rand()%2001-1000);
}
template <typename Position>
void chooseNodeToRemove(AVLtree<Position>& t) {
    bool removed=false;
    Node<Position>* current = t.root();
    char choice=' ';
    while(!removed){
        cout<<"r - right child"<<endl
        <<"l - left child"<<endl
        <<"p - parent"<<endl
        <<"v - value"<<endl
        <<"c - choose"<<endl
        <<"e - cancel"<<endl;
        cin>>choice;
        switch(choice) {
            case 'r':
                if(!current->right()->isExternal())
                    current=current->right();
                else
                    cout<<"That node is external"<<endl<<endl;
                break;
            case 'l':
                if(!current->left()->isExternal())
                    current=current->left();
                else
                    cout<<"That node is external"<<endl<<endl;
                break;
            case 'p':
                if(!current->isRoot())
                    current=current->parent();
                else
                    cout<<"Root has no parent"<<endl<<endl;
                break;
            case 'v':
                cout<<**current<<endl<<endl;
                break;
            case 'c':
                removed=true;
                break;
            case 'e':
                return;
            defalut:
                break;
        }
    }
    t.remove(current);
}

int main() {
    AVLtree<int> t;
    t.addRoot();
    char control=' ';
    while(control!='e'){
        menu();
        cin>>control;
        switch(control) {
            case 'a':
                int toAdd;
                cout<<endl<<"Integer to add:"<<endl;
                cin>>toAdd;
                t.insert(toAdd);
                break;
            case 'r':
                chooseNodeToRemove(t);
                break;
            case 't':
                test(t);
                break;
            case 's':
                eulerianTour(&t);
                break;
        }

    }
    /*
    for(int i=0;i<20;++i) t.insert(rand()%2001-1000);
    t.insert(1);
    t.insert(15);
    t.insert(1);
    eulerianTour(&t);
    cout<<endl<<endl;
    for(int i=0;i<3;++i) t.remove(t.root()->right());
    t.remove(t.root());
    eulerianTour(&t);
    cout<<endl<<endl;
    List<int> l=t.entries();
    Element<int>* current=l.head();
    while(current!=nullptr) {
        cout<<****current<<endl;
        current=current->next();
    }
    cout<<endl<<endl;
    List<int> l2=t.findAll(1);
    current=l2.head();
    while(current!=nullptr) {
        cout<<****current<<endl;
        current=current->next();
    }
    */
}