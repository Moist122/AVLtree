#include "node.hh"

template <typename Position>
Position& Node<Position>::operator*() {
    if(_value==nullptr) throw EmptyNodeException("This node has no value stored.");
    return *_value;
}
template <typename Position>
void Node<Position>::setHeight() {
    if(isExternal()) _height = 0;
    else if(_left->isExternal()) _height = _right->_height+1;
    else if(_right->isExternal()) _height = _left->_height+1;
    else if(_right->_height>=_left->_height) _height = _right->_height+1;
    else                                     _height = _left->_height+1;
}
