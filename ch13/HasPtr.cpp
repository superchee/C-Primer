#include "HasPtr.h"


HasPtr& HasPtr::operator=(const HasPtr& rhs){
    ++(*rhs.use);
    if (--(*use) == 0){
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    use = rhs.use;
    i = rhs.i;
    return *this;
}

HasPtr::~HasPtr(){
    if (--(*use) == 0){
        delete ps;
        delete use;
    }
}