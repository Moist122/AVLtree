#pragma once

template <typename Position>
//element of list of nodes
class Element{
public:
    Element(Node<Position>* v)
        :_value(v), _next(nullptr) {}
    
    Node<Position>* operator*() {return _value;}
        //Node stored in entry
    Element<Position>* next() {return _next;}
        //next element of list
    void addNext(Element<Position>* n) {_next=n;}
        //add element after this
private:
    Node<Position>* _value;
    Element<Position>* _next;
};

template <typename Position>
class List{
public:
    List()
        :_head(nullptr), _tail(nullptr) {}
    ~List();

    Element<Position>* head() {return _head;}
        //head of list
    void append(Node<Position>* v);
        //add v at the end of the list
    Node<Position>* pop();
        //take first element from the list, remove it from list
    bool empty() {return _head==nullptr;}
        //is list empty?
private:
    Element<Position>* _head;
    Element<Position>* _tail;
};