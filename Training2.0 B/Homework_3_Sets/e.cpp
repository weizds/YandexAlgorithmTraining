#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::vector<std::string> testimonies;
    std::vector<std::string> driver_plates;
    std::vector<int> match_counters;
    int m;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    iss >> m;
    for(int i = 0; i < m; ++i){
        std::getline(std::cin, line);
        testimonies.push_back(line);
    }
    int n;
    std::getline(std::cin, line);
    iss.str(line);
    iss.clear();
    iss >> n;
    driver_plates.resize(n);
    match_counters.resize(n);
    for(int i = 0; i < n; ++i){
        std::getline(std::cin, line);
        driver_plates[i] = line;
    }
    for(int i = 0; i < n; ++i){
        std::unordered_set<char> set(driver_plates[i].begin(), driver_plates[i].end());
        for(auto testimony : testimonies){
            int count = 0;
            for(char ch : testimony){
                if(set.find(ch) != set.end())
                    count++;
            }
            if(count == testimony.size())
                ++match_counters[i];
        }
    }
    int max_match = *std::max_element(match_counters.begin(), match_counters.end());
    for(int i = 0; i < n; ++i)
        if(match_counters[i] == max_match)
            std::cout << driver_plates[i] << "\n";
    return 0;
}