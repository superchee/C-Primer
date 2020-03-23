#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>



int main()
{
    std::map<std::string, std::vector<std::string>> famls;

    std::string lastName, chldName;

    //! while(lambda)
    //! go to the discussions on stack overfow for more.
    while ([&]() -> bool {
        std::cout << "Please enter last name:\n";

        return std::cin >> lastName && lastName != "@q";
    }())
    //!  ^^
    //! the () used here is to call the lambda ,otherwise it does not work
    //! go to the post on stack overflow for more detail.

    {
        std::cout << "PLZ Enter children's name:\n";
        while (std::cin >> chldName && chldName != "@q") {
            //! add new items into the vector
            famls[lastName].push_back(chldName);
        }
    }

    //! iterate through the map.
    for (auto e : famls) {
        std::cout << e.first << ":\n";

        //! iterate through the vector.
        for (auto c : e.second) std::cout << c << " ";
        std::cout << "\n";
    }

    return 0;
}