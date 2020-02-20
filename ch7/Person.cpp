#include "Person.h"


const string& Person::GetName() const{
    return name;
}

const string& Person::GetAddress() const{
    return address;
}

istream &read(istream &is, Person &person){
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person){
    os << person.GetName() << " " << person.GetAddress();
    return os;
}