#pragma once

template <typename Position>
class Element{
public:
    Element(Node<Position>* v)
        :_value(v), _next(nullptr) {}
    Position& operator*() {return **_value;}
    Element<Position>* next() {return _next;}
    void addNext(Element<Position>* n) {_next=n;}
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
    void append(Node<Position>* v);
    Position pop();
    bool empty() {return _head==nullptr;}
private:
    Element<Position>* _head;
    Element<Position>* _tail;
};