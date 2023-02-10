#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

int main()
{
    std::unordered_set<int> set;
    std::string line;
    int num;
    
    std::getline(std::cin, line);
    std::istringstream iss(line);
    while(iss >> num) {    
        set.insert(num);
    }
    std::getline(std::cin, line);
    iss.str(line);
    iss.clear();
    int count = 0;
    while(iss >> num) {    
        if(set.find(num) != set.end())
            ++count;
    }
    std::cout << count;
    return 0;
}