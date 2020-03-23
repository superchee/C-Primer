#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>


#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using std::list;
using std::copy;
using std::cout;
using std::endl;

using namespace std;

void elimDups(vector<string> &words);
string make_plural(size_t num, const string &first, const string &second);
void biggies(vector<string> &words, vector<string>::size_type sz);


template <typename Sequence> void print(Sequence const& seq)
{
    for (const auto& i : seq) std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // uses inserter
    list<int> lst1;
    copy(vec.cbegin(), vec.cend(), inserter(lst1, lst1.begin()));
    print(lst1);

    // uses back_inserter
    list<int> lit2;
    copy(vec.cbegin(), vec.cend(), back_inserter(lit2));
    print(lit2);

    // uses front_inserter
    list<int> lst3;
    copy(vec.cbegin(), vec.cend(), front_inserter(lst3));
    print(lst3);
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);

    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b)
                {return a.size() < b.size();});
    
    auto wc = find_if(words.begin(), words.end(),
                [sz](const string &a)
                {return a.size() >= sz;});

    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") 
         << " of length " << sz << " or longer" << endl;

    for_each(wc, words.end(),
            [](const string &s)
            {cout << s << " ";});
    
    cout << endl;

}

string make_plural(size_t num, const string &first, const string &second)
{
    return num>1? first+second:first;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());

    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.end());
}