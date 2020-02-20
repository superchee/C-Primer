#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using std::vector;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
    string line;
    while(getline(cin, line)){
        cout << line << endl;
    }
    return 0;
}