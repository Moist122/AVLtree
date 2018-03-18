#include "AVLtree.hh"
template<typename Position>
void AVLtree<Position>::makeBalanced(Node<Position>* n) {
    n->left()->setHeight();
    std::cout<<n->left()->height()<<std::endl;
    n->right()->setHeight();
    std::cout<<n->right()->height()<<std::endl;
    Node<Position>* newParent=n;
    if(!isBalanced(n)) {
        Node<Position>* z=n;
        Node<Position>* y=(n->left()->height()>n->right()->height() ?
            n->left():n->right());
        Node<Position>* x=(y->left()->height()>y->right()->height() ?
            y->left():y->right());
                        std::cout<<"tri"<<**z<<**y<<**x<<std::endl;
        newParent=trinodeRestructuring(x);
        }
    if(!newParent->isRoot()) makeBalanced(newParent->parent());
}
template <typename Position>
Node<Position>* AVLtree<Position>::trinodeRestructuring(Node<Position>* x) {
    Node<Position>* a, *b, *c;
    if(**x<**(x->parent())&&**x<**(x->parent()->parent())) {
        a=x;
        if(**(x->parent())<**(x->parent()->parent())) {
            b=x->parent();
            c=x->parent()->parent();
        }
        else {
            c=x->parent();
            b=x->parent()->parent();
        }
    }
    else if(**x>**(x->parent())&&**x>**(x->parent()->parent())) {
        c=x;
        if(**(x->parent())<**(x->parent()->parent())) {
            a=x->parent();
            b=x->parent()->parent();
        }
        else {
            b=x->parent();
            a=x->parent()->parent();
        }
    }
    else {
        b=x;
        if(**(x->parent())<**(x->parent()->parent())) {
            a=x->parent();
            c=x->parent()->parent();
        }
        else {
            c=x->parent();
            a=x->parent()->parent();
        }
    }
    std::cout<<"tri"<<**a<<**b<<**c<<std::endl;
    Node<Position>* h1, *h2, *T1, *T2, *T3, *T4;
    T1=a->left();
    std::cout<<"ok"<<std::endl;
    if(a->right()!=b&&a->right()!=c) h1=a->right();
    else if(b->left()!=a) h1=b->left();
    else if(b->right()!=c) h1=b->right();
    else if(c->left()!=a&&c->left()!=b) h1=c->left();
    std::cout<<"ok"<<std::endl;
    if(c->left()!=a&&c->left()!=b) h2=c->left();
    else if(b->right()!=c) h2=b->right();
    else if(b->left()!=a) h2=b->left();
    else if(a->right()!=b&&a->right()!=c) h2=a->right();
    std::cout<<"ok"<<std::endl;
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
    std::cout<<"T set"<<std::endl;
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