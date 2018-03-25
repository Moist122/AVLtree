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

template <typename Position>
bool isTreeBalanced(AVLtree<Position>& t, Node<Position>* n) {
    if(n->isExternal())
        return true;
    if(!(isTreeBalanced(t, n->left())&&isTreeBalanced(t, n->right())))
        return false;
return t.isBalanced(n);
}

void menu() {
    cout<<endl<<"a - add a node"<<endl
    <<"n - add multiple nodes"<<endl
    <<"t - test functions"<<endl
    <<"r - remove node"<<endl
    <<"p - preorder traversal"<<endl
    <<"i - inorder traversal"<<endl
    <<"o - postorder traversal"<<endl
    <<"d - Eulerian tour"<<endl
    <<"s - print entries"<<endl
    <<"e - exit"<<endl;
}
template <typename Position>
void test(AVLtree<Position>& t) {
    cout<<"Inserting 20 random numbers"<<endl;
    char control=' ';
    for(int i=0;i<20;++i) {
        int num=rand()%2001-1000;
        cout<<"Inserting "<<num<<endl;
        int res=t.insert(num);
        if(res)
            cout<<"Tree restructured "<<res<<" times."<<endl;
    }
    cout<<"Type a character to continue."<<endl<<endl;
    cin>>control;
    cout<<"Creating list of entries"<<endl;
    List<Position> l=t.entries();
    Element<int>* current=l.head();
    while(current!=nullptr){
        cout<<****current<<endl;
        current=current->next();
    }
    cout<<"Type a character to continue."<<endl<<endl;
    cin>>control;
    cout<<"Adding number 5 three times."<<endl;
    for(int i=0;i<3;++i) {
        int res=t.insert(5);
        if(res)
            cout<<"Tree restructured "<<res<<" times."<<endl;
    }
    cout<<"Type a character to continue."<<endl<<endl;
    cin>>control;
    cout<<"Removing left child of the root then right child then root"<<endl;
    Node<Position>* toRemove=t.root()->left();
    cout<<"Deleting node with value "<<**toRemove<<endl;
    int res=t.remove(toRemove);
    if(res)
        cout<<"Tree restructured "<<res<<" times."<<endl;
    toRemove=t.root()->left();
    cout<<"Deleting node with value "<<**toRemove<<endl;
    res=t.remove(toRemove);
    if(res)
        cout<<"Tree restructured "<<res<<" times."<<endl;
    toRemove=t.root()->left();
    cout<<"Deleting node with value "<<**toRemove<<endl;
    res=t.remove(toRemove);
    if(res)
        cout<<"Tree restructured "<<res<<" times."<<endl;
    cout<<"Type a character to continue."<<endl<<endl;
    cin>>control;
    cout<<"Performing traversals"<<endl;
    cout<<"Preorder traversal:"<<endl;
    preorderTraversal(&t);
    cout<<endl;
    cout<<"Inorder traversal:"<<endl;
    inorderTraversal(&t);
    cout<<endl;
    cout<<"Postorder traversal:"<<endl;
    postorderTraversal(&t);
    cout<<"Type a character to continue."<<endl<<endl;
    cin>>control;
    cout<<"Searching for number 1997"<<endl;
    if(!(t.find(1997,t.root())->isExternal()))
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;
    int toFind=**(t.root()->left()->right());
    cout<<"Searching for number "<<toFind<<endl;
    if(!(t.find(toFind,t.root())->isExternal()))
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;
    cout<<"Type a character to continue."<<endl<<endl;
    cin>>control;
    cout<<"Searching for all numbers 1997"<<endl;
    List<Position> l2=t.findAll(1997);
    int entriesFound=0;
    current=l2.head();
    while(current!=nullptr){
        entriesFound++;
        current=current->next();
    }
    cout<<"Foud "<<entriesFound<<endl;
    entriesFound=0;
    cout<<"Searching for all numbers 5"<<endl;
    List<Position> l3=t.findAll(5);
    entriesFound=0;
    current=l3.head();
    while(current!=nullptr){
        entriesFound++;
        current=current->next();
    }
    cout<<"Foud "<<entriesFound<<endl;
    cout<<"Type a character to continue."<<endl<<endl;
    cin>>control;
    if(isTreeBalanced(t, t.root()))
        cout<<"Tree is balanced"<<endl;
    else
        cout<<"Tree is not balanced"<<endl;
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
            case 'n':
                int n;
                cout<<endl<<"How many?"<<endl;
                cin>>n;
                for(int i=0;i<n;++i) {
                    int toAdd;
                    cout<<endl<<"Integer to add:"<<endl;
                    cin>>toAdd;
                    t.insert(toAdd);
                }
                break;
            case 'r':
                chooseNodeToRemove(t);
                break;
            case 't':
                test(t);
                break;
            case 'd':
                eulerianTour(&t);
                break;
            case 'p':
                preorderTraversal(&t);
                break;
            case 'i':
                inorderTraversal(&t);
                break;
            case 'o':
                postorderTraversal(&t);
                break;
            case 's':
                List<int> l=t.entries();
                Element<int>* current=l.head();
                while(current!=nullptr){
                    cout<<****current<<endl;
                    current=current->next();
                }
                break;
        }

    }
    return 0;
}