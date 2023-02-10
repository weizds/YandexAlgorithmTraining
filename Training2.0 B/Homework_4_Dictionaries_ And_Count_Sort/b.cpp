#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main() {
    std::map<std::string, int> votes;
    std::string line;
    while(std::getline(std::cin, line)){
        std::string person;
        int value;
        std::istringstream iss(line);
        iss >> person >> value;
        votes[person] += value;
    }
    for(auto it = votes.begin(); it != votes.end(); ++it)
        std::cout << it->first << " " << it->second << "\n";
    return 0;
}