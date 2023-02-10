#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

void print_set(const std::set<int> &s){
    for(int a : s)
        std::cout << a << " ";
    std::cout << "\n";
}

void intersection(std::set<int> &result_set, std::set<int> &current_set){
    for(auto it = current_set.begin(); it != current_set.end();)
        if(result_set.find(*it) == result_set.end())
            it = current_set.erase(it);
        else
            ++it;
    for(auto it = result_set.begin(); it != result_set.end();)
        if(current_set.find(*it) == current_set.end())
            it = result_set.erase(it);
        else
            ++it;
}

int main() {
    std::set<int> result_set;
    std::set<int> current_set;
    std::string line;
    int n = -1;
    while(std::getline(std::cin, line)){
        if(line == "HELP"){
            break;
        }else if(line == "YES"){
            intersection(result_set, current_set);
        }else if(line == "NO"){
            for(int a : current_set)
                result_set.erase(a);
        }else{
            std::istringstream iss(line);
            if(n < 0){
                iss >> n;
                for(int i = 1; i <= n; ++i)
                    result_set.insert(i);
            }else{
                current_set.clear();
                int num;
                while(iss >> num){
                    current_set.insert(num);
                } 
            }
        }
    }
    print_set(result_set);
    return 0;
}