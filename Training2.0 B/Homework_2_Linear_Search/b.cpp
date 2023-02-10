#include <iostream>
#include <vector>

int main() {
    std::vector<int> street;
    int current;
    while(std::cin >> current)
        street.push_back(current);
    int n = street.size();
    std::vector<int> shop_distances;
    shop_distances.resize(n);
    int current_distance = n + 1;
    for(int i = 0; i < n; ++i){
        shop_distances[i] = current_distance;
        if(street[i] == 2)
            current_distance = 1;
        else
            ++current_distance;
    }
    current_distance = n + 1;
    for(int i = n - 1; i >= 0; --i){
        shop_distances[i] = std::min(current_distance, shop_distances[i]);
        if(street[i] == 2)
            current_distance = 1;
        else
            ++current_distance;
    }
    int max_distance = 0;
    for(int i = 0; i < n; ++i)
        if(street[i] == 1)
            max_distance = std::max(max_distance, shop_distances[i]);
    std::cout << max_distance;
    return 0;
}