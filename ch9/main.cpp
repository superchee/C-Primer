#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vTest{1,2,3};
    vector<int>::iterator itr = vTest.begin() + 1;
    int ncheck = *itr;
    vTest.insert(vTest.end(), 4);
    int ntest = *itr;
    cout << ntest << endl;
    return 0;
}