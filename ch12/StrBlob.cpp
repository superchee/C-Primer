#include "StrBlob.h"

using namespace std;

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }

StrBlob::StrBlob(std::initializer_list<std::string> il):
                data(std::make_shared<std::vector<std::string>>(il)){ }



void StrBlob::check(size_type i, const string &msg) const{
    if(i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front(){
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back(){
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::back() const{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}


std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;

}

std::string& StrBlobPtr::deref() const{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
