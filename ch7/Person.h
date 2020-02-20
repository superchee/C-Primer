#include <string>
#include <iostream>

using namespace std;

class Person;



class Person{
    //friends
    friend istream &read(istream &is, Person &person);
    friend ostream &print(ostream &os, const Person &person);
    public:
    //constructors
    Person() = default;
    Person(const string& sname, const string& saddress)
        :name(sname), address(saddress){}
    explicit Person(istream &is) {read(is, *this);}
    const string& GetName() const;
    const string& GetAddress() const;

    private:
    string name;
    string address;

};

istream &read(istream &is, Person &person);
ostream &print(ostream &os, const Person &person);
