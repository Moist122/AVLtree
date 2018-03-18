#include "list.hh"

template <typename Position>
List<Position>::~List() {
    Element<Position>* nextToDelete=_head;
    while(nextToDelete!=nullptr) {
        Element<Position>* currentToDelete=nextToDelete;
        nextToDelete=nextToDelete->next();
        delete currentToDelete;
    }
}
template <typename Position>
void List<Position>::append(Node<Position>* v) {
    if(empty()){
        _head=new Element<Position>(v);
        _tail=_head;
        //std::cout<<***_head<<std::endl;
        }
    else {
        _tail->addNext(new Element<Position>(v));
        _tail=_tail->next();
        //std::cout<<***_tail<<std::endl;
    }
}
template <typename Position>
Position List<Position>::pop() {
    if(!empty()) {
        Element<Position>* oldHead=_head;
        Position toReturn(**oldHead);
        _head=_head->next();
        delete oldHead;
        return toReturn;
    }
}