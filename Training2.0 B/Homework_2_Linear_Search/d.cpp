#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int length = 0;
    int legs_count = 0;
    std::vector<int> legs_position;
    std::cin >> length >> legs_count;
    for(int i = 0; i < legs_count; ++i){
        int position;
        std::cin >> position;
        legs_position.push_back(position);
    }
    auto right_leg = std::lower_bound(legs_position.begin(), legs_position.end(), length/2);
    if((length % 2 == 1) && ((*right_leg) == length / 2)){
        std::cout << *right_leg;
    }else{
        auto left_leg = right_leg;
        if(left_leg != legs_position.begin())
            --left_leg;
        std::cout << *left_leg << " " << *right_leg;
    }
    return 0;
}