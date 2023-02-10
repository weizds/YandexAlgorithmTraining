#include <iostream>
#include <map>

int main() {
    std::map<long long, long long> color_sums;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        long long color;
        long long value;
        std::cin >> color >> value;
        color_sums[color] += value;
    }
    for(auto it = color_sums.begin(); it != color_sums.end(); ++it)
        std::cout << it->first << " " << it->second << "\n";
    return 0;
}