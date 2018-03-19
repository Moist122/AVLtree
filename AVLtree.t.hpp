#include "AVLtree.hh"
template<typename Position>
void AVLtree<Position>::makeBalanced(Node<Position>* n) {
    if(n!=nullptr&&this->_size>2) {
        n->left()->setHeight();
        n->right()->setHeight();
        Node<Position>* newParent=n;
        if(!isBalanced(n)) {
            Node<Position>* z=n;
            Node<Position>* y=(n->left()->height()>n->right()->height() ?
                n->left():n->right());
            Node<Position>* x=(y->left()->height()>y->right()->height() ?
                y->left():y->right());
            newParent=trinodeRestructuring(x);
            }
        if(!newParent->isRoot()) makeBalanced(newParent->parent());
    }
}
template <typename Position>
Node<Position>* AVLtree<Position>::trinodeRestructuring(Node<Position>* x) {
    Node<Position>* a, *b, *c;
    Node<Position> *y=x->parent();
    Node<Position> *z=y->parent();
    if(z->left()==y) {
        c=z;
        if(y->left()==x) {
            a=x;
            b=y;
        }
        else {
            b=x;
            a=y;
        }
    }
    else {
        a=z;
        if(y->left()==x) {
            b=x;
            c=y;
        }
        else {
            c=x;
            b=y;
        }
    }
    Node<Position>* h1, *h2, *T1, *T2, *T3, *T4;
    T1=a->left();
    if(a->right()!=b&&a->right()!=c) h1=a->right();
    else if(b->left()!=a) h1=b->left();
    else if(b->right()!=c) h1=b->right();
    else if(c->left()!=a&&c->left()!=b) h1=c->left();
    if(c->left()!=a&&c->left()!=b) h2=c->left();
    else if(b->right()!=c) h2=b->right();
    else if(b->left()!=a) h2=b->left();
    else if(a->right()!=b&&a->right()!=c) h2=a->right();
    if(!h1->isExternal()&&!h2->isExternal()) {
        if(**h1<**h2) {
            T2=h1;
            T3=h2;
        }
        else {
            T2=h2;
            T3=h1;
        }
    }
    else if(h1->isExternal()&&!h2->isExternal()) {
        if(**(h1->parent())<**h2) {
            T2=h1;
            T3=h2;
        }
        else {
            T2=h2;
            T3=h1;
        }
    }
    else if(!h1->isExternal()&&h2->isExternal()) {
        if(**h1<**(h2->parent())) {
            T2=h1;
            T3=h2;
        }
        else {
            T2=h2;
            T3=h1;
        }
    }
    else {
        T2=h1;
        T3=h2;
    }
    T4= c->right();
    Node<Position>* grandgrandparent=x->parent()->parent()->parent();
    b->setParent(grandgrandparent);
    if(grandgrandparent!=nullptr) {
        if(**b>**grandgrandparent) grandgrandparent->setRight(b);
        else grandgrandparent->setLeft(b);
    }
    else this->setRoot(b);

    b->setLeft(a);
    b->setRight(c);

    a->setParent(b);
    a->setLeft(T1);
    a->setRight(T2);
    T1->setParent(a);
    T2->setParent(a);

    c->setParent(b);
    c->setLeft(T3);
    c->setRight(T4);
    T3->setParent(c);
    T4->setParent(c);

    a->setHeight();
    c->setHeight();
    b->setHeight();

    return b;
}