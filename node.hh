#pragma once

template <typename Position>
class Node {
public:
    Node(Node* p=nullptr, Position* position=nullptr)
        :_parent(p), _value(position), _left(nullptr), _right(nullptr),
        _height(0) {}
    ~Node() {if(_value!=nullptr) delete _value;}

    Position& operator*() {return *_value;}
    void addValue(Position pos) {_value=new Position(pos);}
    Node* parent() const {return _parent;}
    void setParent(Node* p) {_parent=p;}
    Node* right() const {return _right;}
    void setRight(Node* r) {_right=r;}
    Node* left() const {return _left;}
    void setLeft(Node* l) {_left=l;}

    int height() const {return _height;}
    void setHeight();
    bool isRoot() const {return _parent==nullptr;}
    bool isExternal() const {return _right==nullptr&&_left==nullptr;}
    
//private:
    Position* _value;
    Node* _parent;
    Node* _left;
    Node* _right;
    int _height;
};