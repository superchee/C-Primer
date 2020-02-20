#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_data{
    //friend declarations
    
    friend ostream &print(ostream &os, const Sales_data&item);
    friend istream &read(istream &is, Sales_data &item);
    public:
    //constructors added
    //Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p)
        :bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(): Sales_data("",0,0) {}
    explicit Sales_data(const std::string s): Sales_data(s,0,0){}
    explicit Sales_data(std::istream &is): Sales_data() {read(is, *this);}


    string isbn() const {return bookNo;};
    Sales_data& combine(const Sales_data&);


    private:
    //data
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    //ch7
    inline double avg_price() const;

};

istream &read(istream &is, Sales_data &item);
ostream &print(ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);




class Screen;



//Window_mgr
class Window_mgr{
    private:
    vector<Screen> screens;

    public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
};

//Screen
class Screen{
    //friend class Window_mgr;
    friend void Window_mgr::clear(ScreenIndex);
    public:
    using pos = string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd)
        : height(ht), width(wd), contents(ht*wd, ' '){

        }
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, c){

        }
    char get() const{
         return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);

    void some_member() const;

    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(ostream &os){
        do_display(os); return *this;
    }

    const Screen &display(ostream &os) const{
        do_display(os); return *this;
    }

    private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr;

    void do_display(ostream &os) const {os << contents;}
};

//Screen
inline Screen &Screen::move(pos r, pos c){
    pos row = r*width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const{
    pos row = r*width;
    return contents[row+c];
}

inline Screen &Screen::set(char c){
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch){
    contents[r*width + col] = ch;
    return *this;
}






