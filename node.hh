#pragma once

template <typename Position>
class Node {
public:
    Node(Node* p=nullptr, Position* position=nullptr)
        :_parent(p), _value(position), _left(nullptr), _right(nullptr),
        _height(0) {}
    ~Node() {if(_value!=nullptr) delete _value;}

    Position& operator*() {return *_value;}
        //position stored in node
    void addValue(Position pos) {_value=new Position(pos);}
        //adds position to node
    Node* parent() const {return _parent;}
        //parent of this node
    void setParent(Node* p) {_parent=p;}
        //change parent of this node to p
    Node* right() const {return _right;}
        //right child of this node
    void setRight(Node* r) {_right=r;}
        //set right child of this node to r
    Node* left() const {return _left;}
        //left child of this node
    void setLeft(Node* l) {_left=l;}
        //set left child of this node to l

    int height() const {return _height;}
        //height of node in tree
    void setHeight();
        //set height of node based on heights of children
    bool isRoot() const {return _parent==nullptr;}
        //is this node root?
    bool isExternal() const {return _right==nullptr&&_left==nullptr;}
        //is this node external?
    
private:
    Position* _value;
    Node* _parent;
    Node* _left;
    Node* _right;
    int _height;
};