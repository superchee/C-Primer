#include <iostream>
#include "Sales_data.h"
#include <fstream>

using namespace std;


// istream &read(istream &is){
//     string s;
//     // while(getline(is, s)){
//     while(is >> s){
//         cout << "1";
//         cout << s;
//         is >> s;
//     }
//     is.clear();
//     return is;
// }
struct PersonInfo{
    string name;
    vector<string> phones;
};

int main(int argc, char *argv[]){
    ifstream input(argv[1]);
    ofstream output(argv[2], fstream::app);
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total) << std::endl;
                total = trans;
            }
        }
        print(output, total) << std::endl;
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
