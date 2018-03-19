#pragma once
#include <string>
using std::string;
class Exception {
public:
    Exception(const string& err)
        :msg(err) {}
    string getMsg() {return msg;}
protected:
    string msg;
};
class TreeAlreadyRootedException: public Exception {
public:
    TreeAlreadyRootedException(const string& err)
        :Exception(err) {}
};
class UnrootedTreeException: public Exception {
public:
    UnrootedTreeException(const string& err)
        :Exception(err) {}
};
class EmptyNodeException: public Exception {
public:
    EmptyNodeException(const string& err)
        :Exception(err) {}
};