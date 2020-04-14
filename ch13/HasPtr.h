#include <string>



class HasPtr{
    
    friend void swap(HasPtr&, HasPtr&);
    public:
    HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    HasPtr(const HasPtr & hp):
            ps(hp.ps), i(hp.i), use(hp.use) { ++(*use); }

    HasPtr& operator=(const HasPtr&);

    ~HasPtr();

    std::string GetStr() { return *ps;}
    private:
    std::string *ps;
    int i;
    std::size_t *use;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs){
        using std::swap;
        swap(lhs.ps, rhs.ps);
        swap(lhs.i,rhs.i);
}


