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
        }
    else {
        _tail->addNext(new Element<Position>(v));
        _tail=_tail->next();
    }
}
template <typename Position>
Node<Position>* List<Position>::pop() {
    if(!empty()) {
        Element<Position>* oldHead=_head;
        Node<Position>* toReturn=**oldHead;
        _head=_head->next();
        delete oldHead;
        return toReturn;
    }
}